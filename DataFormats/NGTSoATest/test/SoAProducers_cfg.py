import FWCore.ParameterSet.Config as cms

process = cms.Process("SoATEST")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Accelerators_cff")
process.MessageLogger.cerr.FwkReport.reportEvery = 1

# Number of events
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

# Number of threads
process.options = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(10),
    numberOfStreams = cms.untracked.uint32(0)
)

# Input source step3_TP.root
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step4.root'),
)

# Add the producers
process.soaIntegersProducer = cms.EDProducer("SoAIntegersProducer")

process.soaRandomProducer = cms.EDProducer("SoARandomProducer")

process.soaRandIntProducer = cms.EDProducer("SoARandIntProducer")

process.soaTracksProducer = cms.EDProducer("SoATracksProducer",
    generalTracks = cms.InputTag("generalTracks"),
)

# Add the output module
process.out = cms.OutputModule("PoolOutputModule",
                                 fileName = cms.untracked.string('SoAProducers.root'),
                                 # drop everything and keep only soaproducer
                                 outputCommands = cms.untracked.vstring('drop *',
                                                                        'keep *_soaTracksProducer*_*_*',
                                                                        'keep *_soaIntegersProducer*_*_*',
                                                                        'keep *_soaRandomProducer*_*_*',
                                                                        'keep *_soaRandIntProducer*_*_*'),
                                 # Specify the compression
                                 compressionAlgorithm = cms.untracked.string('ZSTD'),
                                 compressionLevel = cms.untracked.int32(3),

                                 splitLevel = cms.untracked.int32(99)
                                 )
# Add to process path
process.path = cms.Path(
    process.soaIntegersProducer +
    process.soaRandomProducer +
    process.soaRandIntProducer +
    process.soaTracksProducer
)
process.outpath = cms.EndPath(process.out)

# Schedule the process
process.schedule = cms.Schedule(process.path, process.outpath)
