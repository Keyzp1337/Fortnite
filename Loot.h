#pragma once

#define ITEM_COLOR_TIER_WHITE ImVec4{ 0.8f, 0.8f, 0.8f, 0.95f }
#define ITEM_COLOR_TIER_GREEN ImVec4{ 0.0f, 0.95f, 0.0f, 0.95f }
#define ITEM_COLOR_TIER_BLUE ImVec4{ 0.2f, 0.4f, 1.0f, 0.95f }
#define ITEM_COLOR_TIER_PURPLE ImVec4{ 0.7f, 0.25f, 0.85f, 0.95f }
#define ITEM_COLOR_TIER_ORANGE ImVec4{ 0.85f, 0.65f, 0.0f, 0.95f }
#define ITEM_COLOR_TIER_GOLD ImVec4{ 0.95f, 0.85f, 0.45f, 0.95f }
#define ITEM_COLOR_TIER_UNKNOWN ImVec4{ 1.0f, 0.0f, 1.0f, 0.95f }

ImVec4 GetItemColor(BYTE tier)
{
	switch (tier)
	{
	case 1:
		return ITEM_COLOR_TIER_WHITE;
	case 2:
		return ITEM_COLOR_TIER_GREEN;
	case 3:
		return ITEM_COLOR_TIER_BLUE;
	case 4:
		return ITEM_COLOR_TIER_PURPLE;
	case 5:
		return ITEM_COLOR_TIER_ORANGE;
	case 6:
	case 7:
		return ITEM_COLOR_TIER_GOLD;
	case 8:
	case 9:
		return ImVec4{ 200 / 255.f, 0 / 255.f, 0 / 255.f, 0.95f };
	case 10:
		return ITEM_COLOR_TIER_UNKNOWN;
	default:
		return ITEM_COLOR_TIER_WHITE;
	}
}

bool LootESP(ImDrawList* Renderer, const char* name, uintptr_t CurrentActor, Vector3 LocalRelativeLocation) {

	if (SDK::Utils::CheckItemInScreen(CurrentActor, Renderer_Defines::Width, Renderer_Defines::Height)) {

		uintptr_t ItemRootComponent = read<uintptr_t>(CurrentActor + StaticOffsets::RootComponent);
		Vector3 ItemPosition = read<Vector3>(ItemRootComponent + StaticOffsets::RelativeLocation);
		float ItemDist = LocalRelativeLocation.Distance(ItemPosition) / 100.f;

		std::string null = xorstr("");

		if (Settings::ChestESP && strstr(name, xorstr("Tiered_Chest"))) {


			if (ItemDist < Settings::MaxESPDistance) {
				Vector3 ChestPosition;
				SDK::Classes::AController::WorldToScreen(ItemPosition, &ChestPosition);

				std::string Text = null + xorstr("Chest [") + std::to_string((int)ItemDist) + xorstr("m]");

				ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());


				Renderer->AddText(ImVec2(ChestPosition.x - TextSize.x / 2, ChestPosition.y - TextSize.y / 2), SettingsColor::ChestESP, Text.c_str());

			}

		}
		else if (Settings::AmmoBoxESP && strstr(name, xorstr("Tiered_Ammo"))) {

			if (ItemDist < Settings::MaxESPDistance) {
				Vector3 AmmoPosition;
				SDK::Classes::AController::WorldToScreen(ItemPosition, &AmmoPosition);

				std::string Text = null + xorstr("AB [") + std::to_string((int)ItemDist) + xorstr("m]");

				ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());


				Renderer->AddText(ImVec2(AmmoPosition.x - TextSize.x / 2, AmmoPosition.y - TextSize.y / 2), SettingsColor::AmmoBox, Text.c_str());

			}

		}
		else if (strstr(name, xorstr("FortPickupAthena")) && Settings::LootESP) {


			if (ItemDist < Settings::MaxESPDistance) {
				auto item = read<uintptr_t>(CurrentActor + StaticOffsets::PrimaryPickupItemEntry + StaticOffsets::ItemDefinition);
				if (!item) return false;

				auto itemName = reinterpret_cast<SDK::Structs::FText*>(read<uintptr_t>(item + StaticOffsets::DisplayName));
				if (!itemName || !itemName->c_str()) return false;
				auto isAmmo = strstr(itemName->c_str(), xorstr("Ammo: "));

				CHAR text[0xFF] = { 0 };
				uintptr_t CurGay = read<uintptr_t>(CurrentActor + StaticOffsets::CurrentWeapon);
				uintptr_t CurRootGay = read<uintptr_t>(CurGay + StaticOffsets::WeaponData);
				uintptr_t bWTier = read<uintptr_t>(CurRootGay + StaticOffsets::Tier);

				wcstombs(text, itemName->c_wstr() + (isAmmo ? 6 : 0), sizeof(text));

				Vector3 LootPosition;

				SDK::Classes::AController::WorldToScreen(ItemPosition, &LootPosition);


				std::string Text = null + text + xorstr(" [") + std::to_string((int)ItemDist) + xorstr("m]");

				ImVec2 TextSize = ImGui::CalcTextSize(Text.c_str());


				Renderer->AddText(ImVec2(LootPosition.x - TextSize.x / 2, LootPosition.y - TextSize.y / 2), SettingsColor::LootESP, Text.c_str());
			}
		}

	}
}