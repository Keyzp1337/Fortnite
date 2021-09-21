#pragma once


namespace Renderer_Defines {
	float Width;
	float Height;
}



namespace Settings
{
	//Aim
	static bool Aim = 1;
	static bool AimPrediction = 0;
	static bool MouseAim = 0;
	int aimbone = 66;
	int smooth = 3;
	static bool SilentAim = 0;
	int FovCircle_Value = 130;
	
	

	//Player ESP
	static bool Box = 1;
	static int  BoxTypeSelected = 1;
	static bool Skeleton = 1;
	static bool DistanceESP = 1;
	static bool SnapLines = 0;
	
	//Loot ESP
	static bool ChestESP = 0;
	static bool LLamaESP = 0;
	static bool WeaponESP = 0;
	static bool LootESP = 0;
	static bool AmmoBoxESP = 0;
	static bool VehiclesESP = 0;


	//Exploits
	static bool NoSpread = 0;
	static bool InstantRevive = 0;
	static bool AimWhileJumping = 0;
	static bool AirStuck = 0;
	static bool RapidFire = 0;
	static float RapidFireValue = 0.001f;
	static bool fov360 = 0;
	static bool FirstCamera = 0;
	static bool godmodeon = 0;
	static bool godmodeoff = 0;
	static bool nobloom = 0;

	//Misc

	static int MaxESPDistance = 300;
	static bool crosshair = 0;
	static bool ShowFovCircle = 1;
	static bool trigger = 0;
	static bool VisibleCheck = 1;
	


}

namespace SettingsColor {
	float FovCircle_float[4] = { 255, 231, 94, 255 };
	ImColor FovCircle = ImColor(255, 231, 94, 255);

	struct rainbow
	{
		float main_red_ = 1.;
		float main_green_ = 0;
		float main_blue_ = 0;
		float main_color_random = 0.0;
		float main_speed = -5.0;
	};
	rainbow r_c;

	namespace initrainbow
	{
		void load_rainbow()
		{
			static float c_colr[3];
			struct tick_
			{
				DWORD tick_count = 0;
				DWORD tick_count2 = 0;
			};
			tick_ t_c_;
			ImGui::ColorConvertRGBtoHSV(r_c.main_red_, r_c.main_green_, r_c.main_blue_, c_colr[0], c_colr[1], c_colr[2]);
			if (GetTickCount() - t_c_.tick_count >= 1)
			{
				if (t_c_.tick_count != t_c_.tick_count)
				{
					c_colr[0] += 0.001f * r_c.main_speed;
					t_c_.tick_count2 = t_c_.tick_count;
				}
				t_c_.tick_count = GetTickCount();
			}
			if (c_colr[0] < 0.0f) c_colr[0] += 1.0f;
			ImGui::ColorConvertHSVtoRGB(c_colr[0], c_colr[1], c_colr[2], r_c.main_red_, r_c.main_green_, r_c.main_blue_);
		}
	}

	//Players ESP VISIBLE
	float Box_float[4] = { 255, 0, 0, 255 };
	ImColor Box = ImColor(255, 0, 0, 255);

	float Skeleton_float[4] = { 255, 231, 94, 255 };
	ImColor Skeleton = ImColor(255, 231, 94, 255);

	float Distance_float[4] = { 255, 0, 0, 255 };
	ImColor Distance = ImColor(255, 0, 0, 255);

	float Snaplines_float[4] = { 255, 0, 0, 255 };
	ImColor Snaplines = ImColor(255, 0, 0, 255);

	float Box_notvisible_float[4] = { 0, 255, 0, 255 };
	ImColor Box_notvisible = ImColor(0, 255, 0, 255);

	float Skeleton_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Skeleton_notvisible = ImColor(255, 231, 94, 255);

	float Distance_notvisible_float[4] = { 0, 255, 0, 255 };
	ImColor Distance_notvisible = ImColor(0, 255, 0, 255);

	float Snaplines_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Snaplines_notvisible = ImColor(255, 231, 94, 255);


	//Loot ESP

	float ChestESP_float[4] = { 255, 255, 0, 255 };
	ImColor ChestESP = ImColor(255, 255, 0, 255);

	float LootESP_float[4] = { 255, 0, 0, 255 };
	ImColor LootESP = ImColor(255, 0, 0, 255);

	float AmmoBox_float[4] = { 75, 184, 72, 255 };
	ImColor AmmoBox = ImColor(75, 184, 72, 255);

	float LLamaESP_float[4] = { 178, 0, 232, 255 };
	ImColor LLamaESP = ImColor(178, 0, 232, 255);

	float VehicleESP_float[4] = { 255, 0, 0, 255 };
	ImColor VehicleESP = ImColor(255, 0, 0, 255);
}