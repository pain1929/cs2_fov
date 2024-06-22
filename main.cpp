#include <iostream>
#include "mem.hpp"
#include "offsets.hpp"
#include "client.dll.hpp"
int main() {
	mem::Process cs2(TEXT("cs2.exe"));
	auto client = cs2.get_module_handle(TEXT("client.dll"));
	auto local_player = cs2.read<mem::addr64>(client + cs2_dumper::offsets::client_dll::dwLocalPlayerPawn);
	auto cam_ser = cs2.read<mem::addr64>(local_player + cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pCameraServices);
	auto fov_addr = cam_ser + cs2_dumper::schemas::client_dll::CCSPlayerBase_CameraServices::m_iFOV;
	while(1){ cs2.write(fov_addr, 120); }
}