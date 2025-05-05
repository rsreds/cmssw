import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import json
import os
import sys

filename = 'SoAProducersSize.json'

# {
# "modules": [
# {
# "events": 100,
# "type": "128falsePhysicsObjTemplatePortableHostCollection_soaRandomProducer_SoAProductDDD_SoATEST.",
# "label": "",
# "size_compressed": 2299023568,
# "size_uncompressed": 2400142024,
# "ratio": 0.95787},
# {
# "events": 100,
# "type": "SimplePhysicsObjs_soaRandomProducer_AoSProductDDD_SoATEST.",
# "label": "",
# "size_compressed": 2298971749,
# "size_uncompressed": 2400085174,
# "ratio": 0.957871},
# {
# "events": 100,
# "type": "SimpleSoAPhysicsObj_soaRandomProducer_SimpleSoAProductDDD_SoATEST.",
# "label": "",
# "size_compressed": 2298968709,
# "size_uncompressed": 2400083400,
# "ratio": 0.95787},
# ...
# {
# "events": 100,
# "type": "SimpleSoAPhysicsObj5_soaTracksProducer_SimpleSoAProductSDF_SoATEST.",
# "label": "",
# "size_compressed": 1971915,
# "size_uncompressed": 3112682,
# "ratio": 0.63351},
# ...
# {
# "events": 100,
# "type": "BranchListIndexes",
# "label": "",
# "size_compressed": 11600,
# "size_uncompressed": 13957,
# "ratio": 0.831124}
# ],
# "resources": [
# {
# "name": "size_uncompressed",
# "description" : "uncompressed size",
# "unit" : "B",
# "title" : "Data Size"
# },
# {
# "name":"size_compressed",
# "description": "compressed size",
# "unit" : "B",
# "title" : "Data Size"
# }
# ],
# "total": {
# "events": 100,
# "size_uncompressed": 54063505772,
# "size_compressed": -1907697980,
# "ratio": -0.0352862
# }
# }

data = {}
modules = []

with open(filename, 'r') as f:
    data = json.load(f)
    # Extract relevant data
    modules = data['modules']

events = data['total']['events']

# Create a dataframe with producer, type, structure, size_compressed, size_uncompressed, ratio
data = []
for module in modules:
    row = {}
    if '_' not in module['type']:
        continue
    row['producer'] = module['type'].split('_')[1]
    structure = module['type'].split('_')[2]
    if 'Product' in structure:
        row['structure'] = structure.split('Product')[0]
        row['types'] = structure.split('Product')[1]
    else:
        row['structure'] = ''
        row['types'] = structure
    # get the sizes
    row['size_compressed'] = module['size_compressed'] / events
    row['size_uncompressed'] = module['size_uncompressed'] / events
    row['ratio'] = module['ratio']
    data.append(row)

colors = ["#5790fc", "#f89c20", "#e42536", "#964a8b", "#9c9ca1", "#7a21dd"]

# Create a dataframe
df = pd.DataFrame(data)
df = df[df['structure'] != '']
df['types'] = df['types'].replace('ConvertDDD', 'DDD*')
df_tracks = df[df['producer'] == 'soaTracksProducer']
df_random = df[df['producer'] == 'soaRandomProducer']
df_randint = df[df['producer'] == 'soaRandIntProducer']
df_integers = df[df['producer'] == 'soaIntegersProducer']

def makeBarPlot(df, title, ylabel, values, filename):
    # if structure in df.columns:
    if 'structure' in df.columns:
        p = df.pivot_table(index='types', columns='structure', values=values).plot.bar(color=colors)
    else:
        p = df.pivot_table(index='types', values=values).plot.bar(color=colors)
        plt.xticks(rotation=0)
    plt.title(title)
    for bar in p.containers:
        plt.bar_label(bar, label_type='center', rotation=90, color='black', fontsize=8)
    
    plt.xlabel('')
    plt.ylabel(ylabel)
    plt.legend(title='')
    if values == 'ratio':
        plt.ylim(0, 1)
    else:
        plt.ylim(0, df[values].max() * 1.01)
    plt.savefig(filename)

# Plot the ratios of the soaTracksProducers
makeBarPlot(df_tracks, 'Compression Ratio for inner positions of generalTracks', 'Compression Ratio', 'ratio', 'plot/ratioTracks.png')
# Plot the ratios of the soaRandomProducers
makeBarPlot(df_random, 'Compression Ratio for random values', 'Compression Ratio', 'ratio', 'plot/ratioRandom.png')
# Plot the ratios of the soaRandIntProducers
makeBarPlot(df_randint, 'Compression Ratio for random integer values', 'Compression Ratio', 'ratio', 'plot/ratioRandInt.png')
# Plot the ratios of the soaIntegersProducers
makeBarPlot(df_integers, 'Compression Ratio for integer numbers', 'Compression Ratio', 'ratio', 'plot/ratioIntegers.png')
# Plot the uncompressed sizes of the soaTracksProducers
makeBarPlot(df_tracks, 'Uncompressed Size for inner positions of generalTracks', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedTracks.png')
# Plot the uncompressed sizes of the soaRandomProducers
makeBarPlot(df_random, 'Uncompressed Size for random values', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedRandom.png')
# Plot the uncompressed sizes of the soaRandIntProducers
makeBarPlot(df_randint, 'Uncompressed Size for random integer values', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedRandInt.png')
# Plot the uncompressed sizes of the soaIntegersProducers
makeBarPlot(df_integers, 'Uncompressed Size for integer numbers', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedIntegers.png')
# Plot the compressed sizes of the soaTracksProducers
makeBarPlot(df_tracks, 'Compressed Size for inner positions of generalTracks', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedTracks.png')
# Plot the compressed sizes of the soaRandomProducers
makeBarPlot(df_random, 'Compressed Size for random values', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedRandom.png')
# Plot the compressed sizes of the soaRandIntProducers
makeBarPlot(df_randint, 'Compressed Size for random integer values', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedRandInt.png')
# Plot the compressed sizes of the soaIntegersProducers
makeBarPlot(df_integers, 'Compressed Size for integer numbres', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedIntegers.png')

# Create dataframe for structure = ''
df = pd.DataFrame(data)
df_vectors = df[df['structure'] == '']
df_vectors.drop(columns=['structure'], inplace=True)
df_vect_tracks = df_vectors[df_vectors['producer'] == 'soaTracksProducer']
df_vect_random = df_vectors[df_vectors['producer'] == 'soaRandomProducer']
df_vect_randint = df_vectors[df_vectors['producer'] == 'soaRandIntProducer']
df_vect_integers = df_vectors[df_vectors['producer'] == 'soaIntegersProducer']

makeBarPlot(df_vect_tracks, 'Compression Ratio for inner positions of generalTracks', 'Compression Ratio', 'ratio', 'plot/ratioTracksVectors.png')
makeBarPlot(df_vect_random, 'Compression Ratio for random values', 'Compression Ratio', 'ratio', 'plot/ratioRandomVectors.png')
makeBarPlot(df_vect_randint, 'Compression Ratio for random integer values', 'Compression Ratio', 'ratio', 'plot/ratioRandIntVectors.png')
makeBarPlot(df_vect_integers, 'Compression Ratio for integer numbers', 'Compression Ratio', 'ratio', 'plot/ratioIntegersVectors.png')
makeBarPlot(df_vect_tracks, 'Uncompressed Size for inner positions of generalTracks', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedTracksVectors.png')
makeBarPlot(df_vect_random, 'Uncompressed Size for random values', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedRandomVectors.png')
makeBarPlot(df_vect_randint, 'Uncompressed Size for random integer values', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedRandIntVectors.png')
makeBarPlot(df_vect_integers, 'Uncompressed Size for integer numbers', 'Uncompressed Size per event (B)', 'size_uncompressed', 'plot/uncompressedIntegersVectors.png')
makeBarPlot(df_vect_tracks, 'Compressed Size for inner positions of generalTracks', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedTracksVectors.png')
makeBarPlot(df_vect_random, 'Compressed Size for random values', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedRandomVectors.png')
makeBarPlot(df_vect_randint, 'Compressed Size for random integer values', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedRandIntVectors.png')
makeBarPlot(df_vect_integers, 'Compressed Size for integer numbres', 'Compressed Size per event (B)', 'size_compressed', 'plot/compressedIntegersVectors.png')
