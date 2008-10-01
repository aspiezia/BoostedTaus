#ifndef RecoBTag_SoftLepton_MuonTagger_h
#define RecoBTag_SoftLepton_MuonTagger_h

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "RecoBTau/JetTagComputer/interface/JetTagComputer.h"
#include "RecoBTag/SoftLepton/interface/LeptonSelector.h"
#include "RecoBTag/SoftLepton/src/MuonTaggerMLP.h"

/**  \class MuonTagger
 *
 *   Implementation of muon b-tagging using a softmax multilayer perceptron neural network
 *
 *   $Date: 2008/04/24 22:15:48 $
 *   $Revision: 1.4 $
 *
 *   \author Andrea 'fwyzard' Bocci, Universita' di Firenze
 */

class MuonTagger : public JetTagComputer {
public:

  /// explicit ctor 
  explicit MuonTagger(const edm::ParameterSet & configuration) : 
    theNet(),
    m_selection( btag::LeptonSelector::option( configuration.getParameter<std::string>("ipSign") ) )
  { 
    uses("slTagInfos"); 
  }
  
  /// dtor
  virtual ~MuonTagger() { }

  /// b-tag a jet based on track-to-jet parameters in the extened info collection
  virtual float discriminator(const TagInfoHelper & tagInfo) const;

private:

  mutable MuonTaggerMLP theNet;

  btag::LeptonSelector::sign m_selection;

};

#endif // RecoBTag_SoftLepton_MuonTagger_h
