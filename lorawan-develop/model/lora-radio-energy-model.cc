
#include "lora-radio-energy-model.h"

#include "ns3/energy-source.h"
#include "ns3/log.h"
#include "ns3/pointer.h"
#include "ns3/simulator.h"

namespace ns3
{
namespace lorawan
{


NS_OBJECT_ENSURE_REGISTERED (LoraRadioEnergyModel);

TypeId
LoraRadioEnergyModel::GetTypeId (void) {
  static TypeId tid = TypeId ("ns3::LoraRadioEnergyModel")
    .SetParent<EnergyModel> ()
    .SetGroupName ("Energy")
    .AddConstructor<LoraRadioEnergyModel> ();
  return tid;
}

LoraRadioEnergyModel::LoraRadioEnergyModel () : m_currentEnergyConsumption (0.0) {
}

LoraRadioEnergyModel::~LoraRadioEnergyModel () {
}

void
LoraRadioEnergyModel::SetEnergySource (Ptr<EnergySource> source) {
  m_source = source;
}

double
LoraRadioEnergyModel::GetCurrentEnergyConsumption () const {
  return m_currentEnergyConsumption;
}

} // namespace ns3
