// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {

	class MunitionInfo {
	public:
		zCOLOR mutionColorInfo;
		int munitionPosX;
		int munitionPosY;

		void Init();
		void MunitionLoop();
		void loadPlayerInfo();

	};

}