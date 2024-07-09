
#include "ns3/basic-energy-source-helper.h"
#include "ns3/class-a-end-device-lorawan-mac.h"
#include "ns3/command-line.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/end-device-lora-phy.h"
#include "ns3/file-helper.h"
#include "ns3/gateway-lora-phy.h"
#include "ns3/gateway-lorawan-mac.h"
#include "ns3/log.h"
#include "ns3/lora-helper.h"
#include "ns3/lora-radio-energy-model-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/names.h"
#include "ns3/node-container.h"
#include "ns3/periodic-sender-helper.h"
#include "ns3/position-allocator.h"
#include "ns3/simulator.h"

#include <algorithm>
#include <ctime>

using namespace ns3;
using namespace lorawan;

using namespace ns3;

int
main (int argc, char *argv[]) {
  // Create nodes
  NodeContainer nodes;
  nodes.Create (10);

  // Install LoRaWAN on nodes
  LoraHelper loraHelper;
  loraHelper.Install (nodes);

  // Install energy model
  BasicEnergySourceHelper energySourceHelper;
  LoraRadioEnergyModelHelper radioEnergyModelHelper;

  energySourceHelper.Set ("BasicEnergySourceInitialEnergyJ", DoubleValue (10000));
  radioEnergyModelHelper.Install (nodes, energySourceHelper);

  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}
    //Get output
    FileHelper fileHelper;
    fileHelper.ConfigureFile("battery-level", FileAggregator::SPACE_SEPARATED);
    fileHelper.WriteProbe("ns3::DoubleProbe", "/Names/EnergySource/RemainingEnergy", "Output");

    //Simulation

    Simulator::Stop(Hours(24));

    Simulator::Run();

    Simulator::Destroy();

    return 0;
}
