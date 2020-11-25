// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	void MunitionInfo::Init() {
		int munitionColorR = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorR", 51);
		int munitionColorG = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorG", 204);
		int munitionColorB = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorB", 51);
		mutionColorInfo = zCOLOR(munitionColorR, munitionColorG, munitionColorB);
		munitionPosX = zoptions->ReadInt("ShowMunitionInfo", "MunitionPosX", 400);
		munitionPosY = zoptions->ReadInt("ShowMunitionInfo", "MunitionPosY", 100);
	}


	void MunitionInfo::MunitionLoop() {
		if (!player || player->attribute[NPC_ATR_HITPOINTS] <= 0)
			return;

		oCItem* gun = player->GetEquippedRangedWeapon();

		if (!gun)
			gun = player->GetWeapon();

		if (!gun || ((gun->mainflag & ITM_CAT_FF) != ITM_CAT_FF) || gun->munition <= 0)
			return;

		player->inventory2.UnpackAllItems();
		oCItem* munition = player->IsInInv(gun->munition, 1);

		zSTRING text = munition ? (munition->description + Z": " + Z munition->amount) : Z"No munition available";

		zCOLOR oldColor = screen->fontColor;
		screen->SetFontColor(mutionColorInfo);
		screen->Print(munitionPosX, munitionPosY, text);
		screen->SetFontColor(oldColor);
	}

}