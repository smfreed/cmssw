#ifndef CLUSTERSUMMARY_CLUSTERVARIABLES_H
#define CLUSTERSUMMARY_CLUSTERVARIABLES_H


#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DataFormats/SiStripDigi/interface/SiStripDigi.h"
#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h"
#include "DataFormats/Common/interface/DetSetVectorNew.h"
#include <numeric>

class ClusterVariables {

 public:

  ClusterVariables(){};
  ~ClusterVariables(){};
  
  ClusterVariables(const SiStripCluster& cluster): cluster_ptr(&cluster){}


  const SiStripCluster * cluster() const {return cluster_ptr;}

  /*
    Returns the number of strips in the Cluster 
  */
  const unsigned clusterSize() const {return cluster()->amplitudes().size();}  


  const std::vector<uint8_t>& stripCharges() const {return cluster()->amplitudes();}

  /*
    Returns the total charge of all the strips in the Cluster 
  */
  uint16_t charge() const    {return   accumulate( stripCharges().begin(), stripCharges().end(), uint16_t(0));}
  

 private:
  
  const SiStripCluster* cluster_ptr;
  
};

#endif
