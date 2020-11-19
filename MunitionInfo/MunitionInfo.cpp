// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	void MunitionInfo::Init() {
		int munitionColorR = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorR", 51);
		int munitionColorG = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorG", 204);
		int munitionColorB = zoptions->ReadInt("ShowMunitionInfo", "MunitionColorB", 51);
		mutionColorInfo = zCOLOR(munitionColorR, munitionColorG, munitionColorB);
		munitionPosX = zoptions->ReadInt("ShowMunitionInfo", "MunitionPosX", 4000);
		munitionPosY = zoptions->ReadInt("ShowMunitionInfo", "MunitionPosY", 100);
	}


	void MunitionInfo::loadPlayerInfo() {
		oCNpc* player = Gothic::Entities::Player;
		player->inventory2.UnpackAllItems();

	}

	void MunitionInfo::MunitionLoop() {
		oCNpc* player = Gothic::Entities::Player;
		oCItem* weapon_ = player->GetWeapon();
		oCItem* rangeWeapon = player->GetEquippedRangedWeapon();


		if (player->IsDead())
			return;

		if (!rangeWeapon && weapon_ && (weapon_->HasFlag(ITM_FLAG_BOW) || weapon_->HasFlag(ITM_FLAG_CROSSBOW))) {
			rangeWeapon = weapon_;
		}

		if (!rangeWeapon)
			return;


		zCListSort<oCItem>& items = player->inventory2.inventory;

		int rangeMunition = rangeWeapon->munition;
		
		int rangeWeaponAmount = 0;
		string munitionName = "";

		for (int i = 0; i < items.GetNumInList(); i++) {
			oCItem* it = items.Get(i);
			if (it->GetInstance() == rangeMunition) {
				rangeWeaponAmount = it->amount;
				munitionName = it->GetDescription().ToChar();
			}
		}

		string ammoDescription; 
		if (rangeWeaponAmount != 0) {			
			ammoDescription = string::Combine("%s: %u", munitionName, rangeWeaponAmount);
		} else {
			ammoDescription = rangeWeapon->HasFlag(ITM_FLAG_CROSSBOW) ? "Нет болтов" : "Нет стрел";
		}

		zCOLOR lastColor = screen->GetColor();
		screen->SetFontColor(mutionColorInfo);
		screen->Print(munitionPosX, munitionPosY, ammoDescription);
		screen->SetFontColor(lastColor);

	}

}