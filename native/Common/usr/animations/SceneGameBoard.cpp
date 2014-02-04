#include "SceneGameBoard.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
SceneGameBoard::SceneGameBoard()
{
	__sceneName = String("SceneGameBoard");
	__fps = 30;
	__view_width = 480;
	__view_height = 320;
	__view_pixel_ratio = 1;
	CocoImage* Image_backround = newResourceImage(String("backround"), String("./assets/images/"));
	{
		Image_backround->viewOptimalWidth = 0;
		Image_backround->viewOptimalHeight = 0;
		Image_backround->addSibling(new CocoImageSibling(String("backround_ldpi.png"), 0.75, 429, 322));
		Image_backround->addSibling(new CocoImageSibling(String("backround_mdpi.png"), 1, 572, 429));
		Image_backround->addSibling(new CocoImageSibling(String("backround_tvdpi.png"), 1.25, 715, 536));
		Image_backround->addSibling(new CocoImageSibling(String("backround_hdpi.png"), 1.5, 858, 644));
		Image_backround->addSibling(new CocoImageSibling(String("backround_xhdpi.png"), 2, 1144, 858));
		Image_backround->textureCellWidth = 572;
		Image_backround->textureCellHeight = 429;
		Image_backround->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_AVATAR_BAR = newResourceImage(String("AVATAR_BAR"), String("./assets/images/"));
	{
		Image_AVATAR_BAR->viewOptimalWidth = 0;
		Image_AVATAR_BAR->viewOptimalHeight = 0;
		Image_AVATAR_BAR->addSibling(new CocoImageSibling(String("AVATAR_BAR_ldpi.png"), 0.75, 166, 31));
		Image_AVATAR_BAR->addSibling(new CocoImageSibling(String("AVATAR_BAR_mdpi.png"), 1, 222, 41));
		Image_AVATAR_BAR->addSibling(new CocoImageSibling(String("AVATAR_BAR_tvdpi.png"), 1.25, 278, 51));
		Image_AVATAR_BAR->addSibling(new CocoImageSibling(String("AVATAR_BAR_hdpi.png"), 1.5, 333, 62));
		Image_AVATAR_BAR->addSibling(new CocoImageSibling(String("AVATAR_BAR_xhdpi.png"), 2, 444, 82));
		Image_AVATAR_BAR->textureCellWidth = 222;
		Image_AVATAR_BAR->textureCellHeight = 41;
		Image_AVATAR_BAR->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_Balance = newResourceImage(String("Balance"), String("./assets/images/"));
	{
		Image_Balance->viewOptimalWidth = 0;
		Image_Balance->viewOptimalHeight = 0;
		Image_Balance->addSibling(new CocoImageSibling(String("Balance_ldpi.png"), 0.75, 69, 33));
		Image_Balance->addSibling(new CocoImageSibling(String("Balance_mdpi.png"), 1, 92, 44));
		Image_Balance->addSibling(new CocoImageSibling(String("Balance_tvdpi.png"), 1.25, 115, 55));
		Image_Balance->addSibling(new CocoImageSibling(String("Balance_hdpi.png"), 1.5, 138, 66));
		Image_Balance->addSibling(new CocoImageSibling(String("Balance_xhdpi.png"), 2, 184, 88));
		Image_Balance->textureCellWidth = 92;
		Image_Balance->textureCellHeight = 44;
		Image_Balance->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_winnings = newResourceImage(String("winnings"), String("./assets/images/"));
	{
		Image_winnings->viewOptimalWidth = 0;
		Image_winnings->viewOptimalHeight = 0;
		Image_winnings->addSibling(new CocoImageSibling(String("winnings_ldpi.png"), 0.75, 69, 33));
		Image_winnings->addSibling(new CocoImageSibling(String("winnings_mdpi.png"), 1, 92, 44));
		Image_winnings->addSibling(new CocoImageSibling(String("winnings_tvdpi.png"), 1.25, 115, 55));
		Image_winnings->addSibling(new CocoImageSibling(String("winnings_hdpi.png"), 1.5, 138, 66));
		Image_winnings->addSibling(new CocoImageSibling(String("winnings_xhdpi.png"), 2, 184, 88));
		Image_winnings->textureCellWidth = 92;
		Image_winnings->textureCellHeight = 44;
		Image_winnings->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_grWhiteStar = newResourceImage(String("grWhiteStar"), String("./assets/images/"));
	{
		Image_grWhiteStar->viewOptimalWidth = 0;
		Image_grWhiteStar->viewOptimalHeight = 0;
		Image_grWhiteStar->addSibling(new CocoImageSibling(String("grWhiteStar_ldpi.png"), 0.75, 18, 18));
		Image_grWhiteStar->addSibling(new CocoImageSibling(String("grWhiteStar_mdpi.png"), 1, 24, 24));
		Image_grWhiteStar->addSibling(new CocoImageSibling(String("grWhiteStar_tvdpi.png"), 1.25, 30, 30));
		Image_grWhiteStar->addSibling(new CocoImageSibling(String("grWhiteStar_hdpi.png"), 1.5, 36, 36));
		Image_grWhiteStar->addSibling(new CocoImageSibling(String("grWhiteStar_xhdpi.png"), 2, 48, 48));
		Image_grWhiteStar->textureCellWidth = 24;
		Image_grWhiteStar->textureCellHeight = 24;
		Image_grWhiteStar->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_openunpressed = newResourceImage(String("openunpressed"), String("./assets/images/"));
	{
		Image_openunpressed->viewOptimalWidth = 0;
		Image_openunpressed->viewOptimalHeight = 0;
		Image_openunpressed->addSibling(new CocoImageSibling(String("openunpressed_ldpi.png"), 0.75, 52, 52));
		Image_openunpressed->addSibling(new CocoImageSibling(String("openunpressed_mdpi.png"), 1, 69, 69));
		Image_openunpressed->addSibling(new CocoImageSibling(String("openunpressed_tvdpi.png"), 1.25, 86, 86));
		Image_openunpressed->addSibling(new CocoImageSibling(String("openunpressed_hdpi.png"), 1.5, 104, 104));
		Image_openunpressed->addSibling(new CocoImageSibling(String("openunpressed_xhdpi.png"), 2, 138, 138));
		Image_openunpressed->textureCellWidth = 69;
		Image_openunpressed->textureCellHeight = 69;
		Image_openunpressed->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_LEONIDAS_body = newResourceImage(String("LEONIDAS_body"), String("./assets/images/"));
	{
		Image_LEONIDAS_body->viewOptimalWidth = 0;
		Image_LEONIDAS_body->viewOptimalHeight = 0;
		Image_LEONIDAS_body->addSibling(new CocoImageSibling(String("LEONIDAS_body_mdpi.png"), 1, 294, 330));
		Image_LEONIDAS_body->addSibling(new CocoImageSibling(String("LEONIDAS_body_xhdpi.png"), 2, 588, 659));
		Image_LEONIDAS_body->textureCellWidth = 294;
		Image_LEONIDAS_body->textureCellHeight = 330;
		Image_LEONIDAS_body->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_LEONIDAS_hand = newResourceImage(String("LEONIDAS_hand"), String("./assets/images/"));
	{
		Image_LEONIDAS_hand->viewOptimalWidth = 0;
		Image_LEONIDAS_hand->viewOptimalHeight = 0;
		Image_LEONIDAS_hand->addSibling(new CocoImageSibling(String("LEONIDAS_hand_mdpi.png"), 1, 43, 105));
		Image_LEONIDAS_hand->addSibling(new CocoImageSibling(String("LEONIDAS_hand_xhdpi.png"), 2, 86, 210));
		Image_LEONIDAS_hand->textureCellWidth = 43;
		Image_LEONIDAS_hand->textureCellHeight = 105;
		Image_LEONIDAS_hand->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_XERXES_Body = newResourceImage(String("XERXES_Body"), String("./assets/images/"));
	{
		Image_XERXES_Body->viewOptimalWidth = 0;
		Image_XERXES_Body->viewOptimalHeight = 0;
		Image_XERXES_Body->addSibling(new CocoImageSibling(String("XERXES_Body_ldpi.png"), 0.75, 51, 76));
		Image_XERXES_Body->addSibling(new CocoImageSibling(String("XERXES_Body_mdpi.png"), 1, 68, 102));
		Image_XERXES_Body->addSibling(new CocoImageSibling(String("XERXES_Body_tvdpi.png"), 1.25, 85, 128));
		Image_XERXES_Body->addSibling(new CocoImageSibling(String("XERXES_Body_hdpi.png"), 1.5, 102, 153));
		Image_XERXES_Body->addSibling(new CocoImageSibling(String("XERXES_Body_xhdpi.png"), 2, 136, 204));
		Image_XERXES_Body->textureCellWidth = 68;
		Image_XERXES_Body->textureCellHeight = 102;
		Image_XERXES_Body->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_Xerxes_Sleeve = newResourceImage(String("Xerxes_Sleeve"), String("./assets/images/"));
	{
		Image_Xerxes_Sleeve->viewOptimalWidth = 0;
		Image_Xerxes_Sleeve->viewOptimalHeight = 0;
		Image_Xerxes_Sleeve->addSibling(new CocoImageSibling(String("Xerxes_Sleeve_ldpi.png"), 0.75, 9, 8));
		Image_Xerxes_Sleeve->addSibling(new CocoImageSibling(String("Xerxes_Sleeve_mdpi.png"), 1, 12, 11));
		Image_Xerxes_Sleeve->addSibling(new CocoImageSibling(String("Xerxes_Sleeve_tvdpi.png"), 1.25, 15, 14));
		Image_Xerxes_Sleeve->addSibling(new CocoImageSibling(String("Xerxes_Sleeve_hdpi.png"), 1.5, 18, 16));
		Image_Xerxes_Sleeve->addSibling(new CocoImageSibling(String("Xerxes_Sleeve_xhdpi.png"), 2, 24, 22));
		Image_Xerxes_Sleeve->textureCellWidth = 12;
		Image_Xerxes_Sleeve->textureCellHeight = 11;
		Image_Xerxes_Sleeve->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_XERXES_hand = newResourceImage(String("XERXES_hand"), String("./assets/images/"));
	{
		Image_XERXES_hand->viewOptimalWidth = 0;
		Image_XERXES_hand->viewOptimalHeight = 0;
		Image_XERXES_hand->addSibling(new CocoImageSibling(String("XERXES_hand_ldpi.png"), 0.75, 21, 19));
		Image_XERXES_hand->addSibling(new CocoImageSibling(String("XERXES_hand_mdpi.png"), 1, 28, 25));
		Image_XERXES_hand->addSibling(new CocoImageSibling(String("XERXES_hand_tvdpi.png"), 1.25, 35, 31));
		Image_XERXES_hand->addSibling(new CocoImageSibling(String("XERXES_hand_hdpi.png"), 1.5, 42, 38));
		Image_XERXES_hand->addSibling(new CocoImageSibling(String("XERXES_hand_xhdpi.png"), 2, 56, 50));
		Image_XERXES_hand->textureCellWidth = 28;
		Image_XERXES_hand->textureCellHeight = 25;
		Image_XERXES_hand->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_XerxesClipHead2 = newResourceImage(String("XerxesClipHead2"), String("./assets/images/"));
	{
		Image_XerxesClipHead2->viewOptimalWidth = 0;
		Image_XerxesClipHead2->viewOptimalHeight = 0;
		Image_XerxesClipHead2->addSibling(new CocoImageSibling(String("XerxesClipHead2_mdpi.png"), 1, 61, 90));
		Image_XerxesClipHead2->addSibling(new CocoImageSibling(String("XerxesClipHead2_xhdpi.png"), 2, 122, 180));
		Image_XerxesClipHead2->textureCellWidth = 61;
		Image_XerxesClipHead2->textureCellHeight = 90;
		Image_XerxesClipHead2->textureGrid = new Float32Array(Array<float> ()(0)(0)(0)(1)(0)(2)(0)(3)(0)(4)(0)(5)(0)(6)(0)(7)(1)(0)(1)(1)(1)(2)(1)(3)(1)(4)(1)(5)(1)(6)(1)(7)(2)(0)(2)(1)(2)(2)(2)(3)(2)(4)(2)(5)(2)(6)(2)(7)(3)(0)(3)(1)(3)(2));
		Image_XerxesClipHead2->addSequence(new CocoSequence(String("Idle"), Array<int> ()(0)(0)(0)(0)(1)(1)(2)(2)(3)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(4)(5)(5)(6)(6)(7)(7)(8)(8)(9)(9)(10)(10)(11)(11)(12)(12)(13)(13)(14)(14)(15)(15)(16)(16)(17)(17)(18)(18)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(19)(20)(20)(21)(21)(22)(22)(23)(23)(24)(24)(25)(25)(26)));
	}
	CocoImage* Image_grid_tile = newResourceImage(String("grid_tile"), String("./assets/images/"));
	{
		Image_grid_tile->viewOptimalWidth = 0;
		Image_grid_tile->viewOptimalHeight = 0;
		Image_grid_tile->addSibling(new CocoImageSibling(String("grid_tile_ldpi.png"), 0.75, 40, 40));
		Image_grid_tile->addSibling(new CocoImageSibling(String("grid_tile_mdpi.png"), 1, 53, 53));
		Image_grid_tile->addSibling(new CocoImageSibling(String("grid_tile_tvdpi.png"), 1.25, 66, 66));
		Image_grid_tile->addSibling(new CocoImageSibling(String("grid_tile_hdpi.png"), 1.5, 80, 80));
		Image_grid_tile->addSibling(new CocoImageSibling(String("grid_tile_xhdpi.png"), 2, 106, 106));
		Image_grid_tile->textureCellWidth = 53;
		Image_grid_tile->textureCellHeight = 53;
		Image_grid_tile->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ticket_price = newResourceImage(String("ticket_price"), String("./assets/images/"));
	{
		Image_ticket_price->viewOptimalWidth = 0;
		Image_ticket_price->viewOptimalHeight = 0;
		Image_ticket_price->addSibling(new CocoImageSibling(String("ticket_price_ldpi.png"), 0.75, 64, 10));
		Image_ticket_price->addSibling(new CocoImageSibling(String("ticket_price_mdpi.png"), 1, 86, 14));
		Image_ticket_price->addSibling(new CocoImageSibling(String("ticket_price_tvdpi.png"), 1.25, 108, 18));
		Image_ticket_price->addSibling(new CocoImageSibling(String("ticket_price_hdpi.png"), 1.5, 129, 21));
		Image_ticket_price->addSibling(new CocoImageSibling(String("ticket_price_xhdpi.png"), 2, 172, 28));
		Image_ticket_price->textureCellWidth = 86;
		Image_ticket_price->textureCellHeight = 14;
		Image_ticket_price->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_PriceTable = newResourceImage(String("PriceTable"), String("./assets/images/"));
	{
		Image_PriceTable->viewOptimalWidth = 0;
		Image_PriceTable->viewOptimalHeight = 0;
		Image_PriceTable->addSibling(new CocoImageSibling(String("PriceTable_ldpi.png"), 0.75, 67, 69));
		Image_PriceTable->addSibling(new CocoImageSibling(String("PriceTable_mdpi.png"), 1, 89, 92));
		Image_PriceTable->addSibling(new CocoImageSibling(String("PriceTable_tvdpi.png"), 1.25, 111, 115));
		Image_PriceTable->addSibling(new CocoImageSibling(String("PriceTable_hdpi.png"), 1.5, 134, 138));
		Image_PriceTable->addSibling(new CocoImageSibling(String("PriceTable_xhdpi.png"), 2, 178, 184));
		Image_PriceTable->textureCellWidth = 89;
		Image_PriceTable->textureCellHeight = 92;
		Image_PriceTable->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_StoneTile_Back = newResourceImage(String("StoneTile_Back"), String("./assets/images/"));
	{
		Image_StoneTile_Back->viewOptimalWidth = 0;
		Image_StoneTile_Back->viewOptimalHeight = 0;
		Image_StoneTile_Back->addSibling(new CocoImageSibling(String("StoneTile_Back_ldpi.png"), 0.75, 47, 47));
		Image_StoneTile_Back->addSibling(new CocoImageSibling(String("StoneTile_Back_mdpi.png"), 1, 63, 63));
		Image_StoneTile_Back->addSibling(new CocoImageSibling(String("StoneTile_Back_tvdpi.png"), 1.25, 79, 79));
		Image_StoneTile_Back->addSibling(new CocoImageSibling(String("StoneTile_Back_hdpi.png"), 1.5, 94, 94));
		Image_StoneTile_Back->addSibling(new CocoImageSibling(String("StoneTile_Back_xhdpi.png"), 2, 126, 126));
		Image_StoneTile_Back->textureCellWidth = 63;
		Image_StoneTile_Back->textureCellHeight = 63;
		Image_StoneTile_Back->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_txtChooseAvatar = newResourceImage(String("ImageSymbol_txtChooseAvatar"), String("./assets/images/"));
	{
		Image_ImageSymbol_txtChooseAvatar->viewOptimalWidth = 0;
		Image_ImageSymbol_txtChooseAvatar->viewOptimalHeight = 0;
		Image_ImageSymbol_txtChooseAvatar->addSibling(new CocoImageSibling(String("txtChooseAvatar_mdpi.png"), 1, 178, 18));
		Image_ImageSymbol_txtChooseAvatar->addSibling(new CocoImageSibling(String("txtChooseAvatar_xhdpi.png"), 2, 356, 36));
		Image_ImageSymbol_txtChooseAvatar->textureCellWidth = 178;
		Image_ImageSymbol_txtChooseAvatar->textureCellHeight = 18;
		Image_ImageSymbol_txtChooseAvatar->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_WIN_Shield = newResourceImage(String("ImageSymbol_WIN_Shield"), String("./assets/images/"));
	{
		Image_ImageSymbol_WIN_Shield->viewOptimalWidth = 0;
		Image_ImageSymbol_WIN_Shield->viewOptimalHeight = 0;
		Image_ImageSymbol_WIN_Shield->addSibling(new CocoImageSibling(String("WIN_Shield_mdpi.png"), 1, 357, 321));
		Image_ImageSymbol_WIN_Shield->addSibling(new CocoImageSibling(String("WIN_Shield_xhdpi.png"), 2, 714, 642));
		Image_ImageSymbol_WIN_Shield->textureCellWidth = 357;
		Image_ImageSymbol_WIN_Shield->textureCellHeight = 321;
		Image_ImageSymbol_WIN_Shield->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_WIN_Logo = newResourceImage(String("ImageSymbol_WIN_Logo"), String("./assets/images/"));
	{
		Image_ImageSymbol_WIN_Logo->viewOptimalWidth = 0;
		Image_ImageSymbol_WIN_Logo->viewOptimalHeight = 0;
		Image_ImageSymbol_WIN_Logo->addSibling(new CocoImageSibling(String("WIN_Logo_mdpi.png"), 1, 334, 300));
		Image_ImageSymbol_WIN_Logo->addSibling(new CocoImageSibling(String("WIN_Logo_xhdpi.png"), 2, 668, 600));
		Image_ImageSymbol_WIN_Logo->textureCellWidth = 334;
		Image_ImageSymbol_WIN_Logo->textureCellHeight = 300;
		Image_ImageSymbol_WIN_Logo->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_cloud2 = newResourceImage(String("ImageSymbol_cloud2"), String("./assets/images/"));
	{
		Image_ImageSymbol_cloud2->viewOptimalWidth = 0;
		Image_ImageSymbol_cloud2->viewOptimalHeight = 0;
		Image_ImageSymbol_cloud2->addSibling(new CocoImageSibling(String("cloud2_mdpi.png"), 1, 190, 58));
		Image_ImageSymbol_cloud2->addSibling(new CocoImageSibling(String("cloud2_xhdpi.png"), 2, 380, 116));
		Image_ImageSymbol_cloud2->textureCellWidth = 190;
		Image_ImageSymbol_cloud2->textureCellHeight = 58;
		Image_ImageSymbol_cloud2->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_cloud5 = newResourceImage(String("ImageSymbol_cloud5"), String("./assets/images/"));
	{
		Image_ImageSymbol_cloud5->viewOptimalWidth = 0;
		Image_ImageSymbol_cloud5->viewOptimalHeight = 0;
		Image_ImageSymbol_cloud5->addSibling(new CocoImageSibling(String("cloud5_mdpi.png"), 1, 102, 25));
		Image_ImageSymbol_cloud5->addSibling(new CocoImageSibling(String("cloud5_xhdpi.png"), 2, 204, 50));
		Image_ImageSymbol_cloud5->textureCellWidth = 102;
		Image_ImageSymbol_cloud5->textureCellHeight = 25;
		Image_ImageSymbol_cloud5->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_TileOnly = newResourceImage(String("TileOnly"), String("./assets/images/"));
	{
		Image_TileOnly->viewOptimalWidth = 0;
		Image_TileOnly->viewOptimalHeight = 0;
		Image_TileOnly->addSibling(new CocoImageSibling(String("TileOnly_ldpi.png"), 0.75, 36, 37));
		Image_TileOnly->addSibling(new CocoImageSibling(String("TileOnly_mdpi.png"), 1, 48, 49));
		Image_TileOnly->addSibling(new CocoImageSibling(String("TileOnly_tvdpi.png"), 1.25, 60, 61));
		Image_TileOnly->addSibling(new CocoImageSibling(String("TileOnly_hdpi.png"), 1.5, 72, 74));
		Image_TileOnly->addSibling(new CocoImageSibling(String("TileOnly_xhdpi.png"), 2, 96, 98));
		Image_TileOnly->textureCellWidth = 48;
		Image_TileOnly->textureCellHeight = 49;
		Image_TileOnly->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_buyunpressed = newResourceImage(String("buyunpressed"), String("./assets/images/"));
	{
		Image_buyunpressed->viewOptimalWidth = 0;
		Image_buyunpressed->viewOptimalHeight = 0;
		Image_buyunpressed->addSibling(new CocoImageSibling(String("buyunpressed_mdpi.png"), 1, 125, 125));
		Image_buyunpressed->addSibling(new CocoImageSibling(String("buyunpressed_xhdpi.png"), 2, 250, 250));
		Image_buyunpressed->textureCellWidth = 125;
		Image_buyunpressed->textureCellHeight = 125;
		Image_buyunpressed->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_SpriteSymbol_XerxesAvatar = newResourceImage(String("SpriteSymbol_XerxesAvatar"), String("./assets/images/"));
	{
		Image_SpriteSymbol_XerxesAvatar->viewOptimalWidth = 0;
		Image_SpriteSymbol_XerxesAvatar->viewOptimalHeight = 0;
		Image_SpriteSymbol_XerxesAvatar->addSibling(new CocoImageSibling(String("XerxesAvatar_mdpi.png"), 1, 160, 160));
		Image_SpriteSymbol_XerxesAvatar->addSibling(new CocoImageSibling(String("XerxesAvatar_xhdpi.png"), 2, 320, 320));
		Image_SpriteSymbol_XerxesAvatar->textureCellWidth = 160;
		Image_SpriteSymbol_XerxesAvatar->textureCellHeight = 160;
		Image_SpriteSymbol_XerxesAvatar->textureGrid = new Float32Array(Array<float> ()(0)(0)(0)(1)(0)(2)(1)(0)(1)(1)(1)(2)(2)(0));
		Image_SpriteSymbol_XerxesAvatar->addSequence(new CocoSequence(String("idle"), Array<int> ()(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(1)(1)(1)(2)(2)(2)(3)(3)(3)(4)(4)(4)(5)(5)(5)(6)(6)(6)));
	}
	CocoImage* Image_SpriteSymbol_SwordsAvatar = newResourceImage(String("SpriteSymbol_SwordsAvatar"), String("./assets/images/"));
	{
		Image_SpriteSymbol_SwordsAvatar->viewOptimalWidth = 0;
		Image_SpriteSymbol_SwordsAvatar->viewOptimalHeight = 0;
		Image_SpriteSymbol_SwordsAvatar->addSibling(new CocoImageSibling(String("SwordsAvatar_mdpi.png"), 1, 160, 160));
		Image_SpriteSymbol_SwordsAvatar->addSibling(new CocoImageSibling(String("SwordsAvatar_xhdpi.png"), 2, 320, 320));
		Image_SpriteSymbol_SwordsAvatar->textureCellWidth = 160;
		Image_SpriteSymbol_SwordsAvatar->textureCellHeight = 160;
		Image_SpriteSymbol_SwordsAvatar->textureGrid = new Float32Array(Array<float> ()(0)(0)(0)(2)(0)(3)(0)(4)(0)(5)(1)(0)(1)(1)(1)(2)(1)(3)(1)(4)(1)(5)(2)(0)(2)(1)(2)(2)(2)(3)(2)(4)(2)(5)(3)(0)(3)(1)(3)(2)(3)(3)(3)(4)(3)(5)(4)(0)(4)(1)(4)(2)(4)(3)(4)(4)(4)(5)(5)(0));
		Image_SpriteSymbol_SwordsAvatar->addSequence(new CocoSequence(String("idle"), Array<int> ()(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(10)(11)(12)(13)(14)(15)(16)(17)(18)(19)(20)(21)(22)(23)(24)(25)(26)(27)(28)(29)));
	}
	CocoImage* Image_SpriteSymbol_LeonidasAvatar = newResourceImage(String("SpriteSymbol_LeonidasAvatar"), String("./assets/images/"));
	{
		Image_SpriteSymbol_LeonidasAvatar->viewOptimalWidth = 0;
		Image_SpriteSymbol_LeonidasAvatar->viewOptimalHeight = 0;
		Image_SpriteSymbol_LeonidasAvatar->addSibling(new CocoImageSibling(String("LeonidasAvatar_mdpi.png"), 1, 160, 160));
		Image_SpriteSymbol_LeonidasAvatar->addSibling(new CocoImageSibling(String("LeonidasAvatar_xhdpi.png"), 2, 320, 320));
		Image_SpriteSymbol_LeonidasAvatar->textureCellWidth = 160;
		Image_SpriteSymbol_LeonidasAvatar->textureCellHeight = 160;
		Image_SpriteSymbol_LeonidasAvatar->textureGrid = new Float32Array(Array<float> ()(0)(0)(0)(1)(0)(2)(0)(3)(0)(4)(0)(5)(0)(6)(0)(7)(0)(8)(0)(9)(0)(10)(0)(11)(1)(0)(1)(1)(1)(2)(1)(3)(1)(4)(1)(5)(1)(6)(1)(7)(1)(8)(1)(9)(1)(10)(1)(11)(2)(0)(2)(1)(2)(2)(2)(3)(2)(4)(2)(5)(2)(6)(2)(7)(2)(8)(2)(9)(2)(10)(2)(11)(3)(0)(3)(1)(3)(2)(3)(3)(3)(4)(3)(5)(3)(6)(3)(7)(3)(8)(3)(9)(3)(10)(3)(11)(4)(0)(4)(1)(4)(2)(4)(3)(4)(4)(4)(5)(4)(6)(4)(7)(4)(8)(4)(9)(4)(10)(4)(11)(5)(0)(5)(1)(5)(2)(5)(3)(5)(4)(5)(5)(5)(6)(5)(7)(5)(8)(5)(9)(5)(10)(5)(11)(6)(0)(6)(1)(6)(2)(6)(3)(6)(4));
		Image_SpriteSymbol_LeonidasAvatar->addSequence(new CocoSequence(String("idle"), Array<int> ()(0)(0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(10)(11)(12)(13)(14)(15)(16)(17)(18)(19)(19)(20)(21)(22)(23)(24)(25)(26)(27)(28)(29)(30)(31)(32)(33)(34)(35)(36)(37)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(38)(39)(40)(41)(42)(43)(44)(45)(46)(47)(48)(49)(50)(51)(52)(53)(54)(55)(56)(57)(58)(59)(60)(61)(62)(63)(64)(65)(66)(67)(68)(69)(70)(71)(72)(73)(74)(75)(76)));
	}
	CocoImage* Image_ImageSymbol_avatarArmor = newResourceImage(String("ImageSymbol_avatarArmor"), String("./assets/images/"));
	{
		Image_ImageSymbol_avatarArmor->viewOptimalWidth = 0;
		Image_ImageSymbol_avatarArmor->viewOptimalHeight = 0;
		Image_ImageSymbol_avatarArmor->addSibling(new CocoImageSibling(String("avatarArmor_mdpi.png"), 1, 160, 160));
		Image_ImageSymbol_avatarArmor->addSibling(new CocoImageSibling(String("avatarArmor_xhdpi.png"), 2, 320, 320));
		Image_ImageSymbol_avatarArmor->textureCellWidth = 160;
		Image_ImageSymbol_avatarArmor->textureCellHeight = 160;
		Image_ImageSymbol_avatarArmor->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_avatarSpartan = newResourceImage(String("ImageSymbol_avatarSpartan"), String("./assets/images/"));
	{
		Image_ImageSymbol_avatarSpartan->viewOptimalWidth = 0;
		Image_ImageSymbol_avatarSpartan->viewOptimalHeight = 0;
		Image_ImageSymbol_avatarSpartan->addSibling(new CocoImageSibling(String("avatarSpartan_mdpi.png"), 1, 160, 160));
		Image_ImageSymbol_avatarSpartan->addSibling(new CocoImageSibling(String("avatarSpartan_xhdpi.png"), 2, 320, 320));
		Image_ImageSymbol_avatarSpartan->textureCellWidth = 160;
		Image_ImageSymbol_avatarSpartan->textureCellHeight = 160;
		Image_ImageSymbol_avatarSpartan->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_ImageSymbol_avatarPersian = newResourceImage(String("ImageSymbol_avatarPersian"), String("./assets/images/"));
	{
		Image_ImageSymbol_avatarPersian->viewOptimalWidth = 0;
		Image_ImageSymbol_avatarPersian->viewOptimalHeight = 0;
		Image_ImageSymbol_avatarPersian->addSibling(new CocoImageSibling(String("avatarPersian_mdpi.png"), 1, 160, 160));
		Image_ImageSymbol_avatarPersian->addSibling(new CocoImageSibling(String("avatarPersian_xhdpi.png"), 2, 320, 320));
		Image_ImageSymbol_avatarPersian->textureCellWidth = 160;
		Image_ImageSymbol_avatarPersian->textureCellHeight = 160;
		Image_ImageSymbol_avatarPersian->textureGrid = new Float32Array(Array<float> ()(0)(0));
	}
	CocoImage* Image_SpriteSymbol_LeonidasClipHead2 = newResourceImage(String("SpriteSymbol_LeonidasClipHead2"), String("./assets/images/"));
	{
		Image_SpriteSymbol_LeonidasClipHead2->viewOptimalWidth = 0;
		Image_SpriteSymbol_LeonidasClipHead2->viewOptimalHeight = 0;
		Image_SpriteSymbol_LeonidasClipHead2->addSibling(new CocoImageSibling(String("LeonidasClipHead2_mdpi.png"), 1, 62, 59));
		Image_SpriteSymbol_LeonidasClipHead2->addSibling(new CocoImageSibling(String("LeonidasClipHead2_xhdpi.png"), 2, 124, 118));
		Image_SpriteSymbol_LeonidasClipHead2->textureCellWidth = 62;
		Image_SpriteSymbol_LeonidasClipHead2->textureCellHeight = 59;
		Image_SpriteSymbol_LeonidasClipHead2->textureGrid = new Float32Array(Array<float> ()(0)(0)(0)(1)(1)(0)(1)(1));
		Image_SpriteSymbol_LeonidasClipHead2->addSequence(new CocoSequence(String("Idle"), Array<int> ()(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(0)(1)(1)(1)(1)(1)(1)(2)(2)(2)(2)(2)(2)(3)(3)(3)));
	}
	__root = new CocoClip();
	__root->__instanceName = String("root");
	__root->__scene = this;
	__root->__timeline->clear();
	__root->__timeline->addLabelEx(48, String("IntroAnimationDone"));
	__root->__timeline->addLabelEx(49, String("JumpingAvatars"));
	__root->__timeline->addLabelEx(71, String("WaitToChooseAvatar"));
	__root->__timeline->addLabelEx(72, String("WaitToBuyTicket"));
	__root->__timeline->addLabelEx(73, String("WaitToScratch"));
	__root->__timeline->addLabelEx(74, String("WinAnim"));
	__root->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
	{
		CocoClip* inst1 = new CocoClip(nullptr);
		inst1->__instanceName = String("Background");
		__root->addChild(inst1);
		inst1->__scene = this;
		inst1->__timeline->clear();
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/Background.ogg"), true, 0), false, false, String(""));
		{
			CocoClip* inst2 = new CocoClip(Image_backround);
			inst2->__instanceName = String(":: backround");
			inst1->addChild(inst2);
			inst2->__scene = this;
			inst2->__timeline->clear();
			inst2->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst3 = new CocoClip(nullptr);
		inst3->__instanceName = String("ChooseAvatar");
		__root->addChild(inst3);
		inst3->__scene = this;
		inst3->__timeline->clear();
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 71, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 87, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 72, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 87, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
		{
			CocoClip* inst4 = new CocoClip(nullptr);
			inst4->__instanceName = String("AVATAR_BAR1");
			inst3->addChild(inst4);
			inst4->__scene = this;
			inst4->__timeline->clear();
			inst4->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.901623, 0.868781, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst4->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.001803, 1.002439, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst4->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.901623, 0.868781, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst5 = new CocoClip(Image_AVATAR_BAR);
				inst5->__instanceName = String(":: AVATAR_BAR");
				inst4->addChild(inst5);
				inst5->__scene = this;
				inst5->__timeline->clear();
				inst5->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst6 = new CocoClip(nullptr);
			inst6->__instanceName = String("text");
			inst3->addChild(inst6);
			inst6->__scene = this;
			inst6->__timeline->clear();
			inst6->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.883147, 0.866666, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst6->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.000899, 0.982222, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst6->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.883147, 0.866666, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst7 = new CocoClip(Image_ImageSymbol_txtChooseAvatar);
				inst7->__instanceName = String(":: ChooseAvatarBar");
				inst6->addChild(inst7);
				inst7->__scene = this;
				inst7->__timeline->clear();
				inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
		}
		CocoClip* inst8 = new CocoClip(nullptr);
		inst8->__instanceName = String("Avatar_Armor");
		__root->addChild(inst8);
		inst8->__scene = this;
		inst8->__timeline->clear();
		inst8->__timeline->addLabelEx(0, String("Init"));
		inst8->__timeline->addLabelEx(1, String("Enable"));
		inst8->__timeline->addLabelEx(10, String("Disable"));
		inst8->__timeline->addLabelEx(20, String("Select"));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 113, 242, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 34, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 113, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 39, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 113, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 58, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 113, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 64, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 113, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 70, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true, 113, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst9 = new CocoClip(nullptr);
			inst9->__instanceName = String("TileOnly1");
			inst8->addChild(inst9);
			inst9->__scene = this;
			inst9->__timeline->clear();
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst9->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst10 = new CocoClip(Image_TileOnly);
				inst10->__instanceName = String(":: TileOnly");
				inst9->addChild(inst10);
				inst10->__scene = this;
				inst10->__timeline->clear();
				inst10->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst11 = new CocoClip(nullptr);
			inst11->__instanceName = String("ArmorAvatar");
			inst8->addChild(inst11);
			inst11->__scene = this;
			inst11->__timeline->clear();
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst11->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 13, 1.2, 1.2, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst12 = new CocoClip(Image_ImageSymbol_avatarArmor);
				inst12->__instanceName = String("avatarArmor1");
				inst11->addChild(inst12);
				inst12->__scene = this;
				inst12->__timeline->clear();
				inst12->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				CocoClip* inst13 = new CocoClip(nullptr);
				inst13->__instanceName = String("inst1_grWhiteStar");
				inst11->addChild(inst13);
				inst13->__scene = this;
				inst13->__timeline->clear();
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 1.686667, 1.686667, 135, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 29, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 2.22, 2.22, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 39, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 66, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 77, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.969333, 0.969333, 135, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 87, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 96, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 1.478, 1.478, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst13->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 28,  -37, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst14 = new CocoClip(Image_grWhiteStar);
					inst14->__instanceName = String(":: grWhiteStar");
					inst13->addChild(inst14);
					inst14->__scene = this;
					inst14->__timeline->clear();
					inst14->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst15 = new CocoClip(nullptr);
				inst15->__instanceName = String("inst2_grWhiteStar");
				inst11->addChild(inst15);
				inst15->__scene = this;
				inst15->__timeline->clear();
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 1.047333, 1.047333, 135, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 29, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 1.316667, 1.316667, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 39, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 66, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 77, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 1.922, 1.922, 135, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 87, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 96, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 2.548, 2.548, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst15->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -26, 28, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst16 = new CocoClip(Image_grWhiteStar);
					inst16->__instanceName = String(":: grWhiteStar");
					inst15->addChild(inst16);
					inst16->__scene = this;
					inst16->__timeline->clear();
					inst16->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
			}
			CocoClip* inst17 = new CocoClip(nullptr);
			inst17->__instanceName = String("Actions");
			inst8->addChild(inst17);
			inst17->__scene = this;
			inst17->__timeline->clear();
			inst17->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst17->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst17->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst17->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst18 = new CocoClip(nullptr);
		inst18->__instanceName = String("Avatar_Swords");
		__root->addChild(inst18);
		inst18->__scene = this;
		inst18->__timeline->clear();
		inst18->__timeline->addLabelEx(0, String("Init"));
		inst18->__timeline->addLabelEx(1, String("Enable"));
		inst18->__timeline->addLabelEx(10, String("Disable"));
		inst18->__timeline->addLabelEx(20, String("Select"));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 29, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 67.8, 242, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 38, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 67.8, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 43, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 67.8, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 56, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 67.8, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 62, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 67.8, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst18->__timeline->addKeyFrameEx(nullptr, nullptr, 68, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true, 67.8, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst19 = new CocoClip(nullptr);
			inst19->__instanceName = String("TileOnly1");
			inst18->addChild(inst19);
			inst19->__scene = this;
			inst19->__timeline->clear();
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst19->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst20 = new CocoClip(Image_TileOnly);
				inst20->__instanceName = String(":: TileOnly");
				inst19->addChild(inst20);
				inst20->__scene = this;
				inst20->__timeline->clear();
				inst20->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst21 = new CocoClip(nullptr);
			inst21->__instanceName = String("SwordsAvatar");
			inst18->addChild(inst21);
			inst21->__scene = this;
			inst21->__timeline->clear();
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 10, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst21->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 10, 1.3, 1.3, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			{
				CocoClip* inst22 = new CocoClip(Image_SpriteSymbol_SwordsAvatar);
				inst22->__instanceName = String("Layer1");
				inst21->addChild(inst22);
				inst22->__scene = this;
				inst22->__timeline->clear();
				inst22->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst23 = new CocoClip(nullptr);
			inst23->__instanceName = String("ActionsSwords");
			inst18->addChild(inst23);
			inst23->__scene = this;
			inst23->__timeline->clear();
			inst23->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst23->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst23->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst23->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst24 = new CocoClip(nullptr);
		inst24->__instanceName = String("Avatar_Persian");
		__root->addChild(inst24);
		inst24->__scene = this;
		inst24->__timeline->clear();
		inst24->__timeline->addLabelEx(0, String("Init"));
		inst24->__timeline->addLabelEx(1, String("Enable"));
		inst24->__timeline->addLabelEx(10, String("Disable"));
		inst24->__timeline->addLabelEx(20, String("Select"));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 33, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 22.6, 243.1364, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 42, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 22.6, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 47, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 22.6, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 55, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 22.6, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 61, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 22.6, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst24->__timeline->addKeyFrameEx(nullptr, nullptr, 67, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true, 22.6, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst25 = new CocoClip(nullptr);
			inst25->__instanceName = String("TileOnly1");
			inst24->addChild(inst25);
			inst25->__scene = this;
			inst25->__timeline->clear();
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst25->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst26 = new CocoClip(Image_TileOnly);
				inst26->__instanceName = String(":: TileOnly");
				inst25->addChild(inst26);
				inst26->__scene = this;
				inst26->__timeline->clear();
				inst26->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst27 = new CocoClip(nullptr);
			inst27->__instanceName = String("PersianAvatar");
			inst24->addChild(inst27);
			inst27->__scene = this;
			inst27->__timeline->clear();
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst27->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 2, 12, 1.2, 1.2, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst28 = new CocoClip(Image_ImageSymbol_avatarPersian);
				inst28->__instanceName = String("avatarPersian1");
				inst27->addChild(inst28);
				inst28->__scene = this;
				inst28->__timeline->clear();
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.183, 1.183, 6.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.167, 1.167,  -7.7, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 44, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 50, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.183, 1.183, 6.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 55, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.167, 1.167,  -7.7, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 60, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst28->__timeline->addKeyFrameEx(nullptr, nullptr, 84, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst29 = new CocoClip(nullptr);
			inst29->__instanceName = String("Actions");
			inst24->addChild(inst29);
			inst29->__scene = this;
			inst29->__timeline->clear();
			inst29->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst29->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst29->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst29->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst30 = new CocoClip(nullptr);
		inst30->__instanceName = String("Avatar_Spartan");
		__root->addChild(inst30);
		inst30->__scene = this;
		inst30->__timeline->clear();
		inst30->__timeline->addLabelEx(0, String("Init"));
		inst30->__timeline->addLabelEx(1, String("Enable"));
		inst30->__timeline->addLabelEx(10, String("Disable"));
		inst30->__timeline->addLabelEx(20, String("Select"));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 33, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -22.6, 243.1364, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 42, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -22.6, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 47, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -22.6, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 53, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -22.6, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 59, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -22.6, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst30->__timeline->addKeyFrameEx(nullptr, nullptr, 65, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true,  -22.6, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst31 = new CocoClip(nullptr);
			inst31->__instanceName = String("TileOnly1");
			inst30->addChild(inst31);
			inst31->__scene = this;
			inst31->__timeline->clear();
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst31->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst32 = new CocoClip(Image_TileOnly);
				inst32->__instanceName = String(":: TileOnly");
				inst31->addChild(inst32);
				inst32->__scene = this;
				inst32->__timeline->clear();
				inst32->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst33 = new CocoClip(nullptr);
			inst33->__instanceName = String("SpartanAvatar");
			inst30->addChild(inst33);
			inst33->__scene = this;
			inst33->__timeline->clear();
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst33->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 13, 1.2, 1.2, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst34 = new CocoClip(Image_ImageSymbol_avatarSpartan);
				inst34->__instanceName = String("avatarSpartan1");
				inst33->addChild(inst34);
				inst34->__scene = this;
				inst34->__timeline->clear();
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.183, 1.183,  -15, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1.183, 1.183, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.166, 1.166, 15, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 40, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst34->__timeline->addKeyFrameEx(nullptr, nullptr, 82, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst35 = new CocoClip(nullptr);
			inst35->__instanceName = String("Actions");
			inst30->addChild(inst35);
			inst35->__scene = this;
			inst35->__timeline->clear();
			inst35->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst35->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst35->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst35->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst36 = new CocoClip(nullptr);
		inst36->__instanceName = String("Avatar_Xerxes");
		__root->addChild(inst36);
		inst36->__scene = this;
		inst36->__timeline->clear();
		inst36->__timeline->addLabelEx(0, String("Init"));
		inst36->__timeline->addLabelEx(1, String("Enable"));
		inst36->__timeline->addLabelEx(10, String("Disable"));
		inst36->__timeline->addLabelEx(20, String("Select"));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 29, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -67.8, 243.96, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 38, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -67.8, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 43, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -67.8, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 50, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -67.8, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 56, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -67.8, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst36->__timeline->addKeyFrameEx(nullptr, nullptr, 62, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true,  -67.8, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst37 = new CocoClip(nullptr);
			inst37->__instanceName = String("TileOnly1");
			inst36->addChild(inst37);
			inst37->__scene = this;
			inst37->__timeline->clear();
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst37->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst38 = new CocoClip(Image_TileOnly);
				inst38->__instanceName = String(":: TileOnly");
				inst37->addChild(inst38);
				inst38->__scene = this;
				inst38->__timeline->clear();
				inst38->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst39 = new CocoClip(nullptr);
			inst39->__instanceName = String("XerxesAvatar");
			inst36->addChild(inst39);
			inst39->__scene = this;
			inst39->__timeline->clear();
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst39->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 5, 1.3, 1.3, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst40 = new CocoClip(Image_SpriteSymbol_XerxesAvatar);
				inst40->__instanceName = String("Layer1");
				inst39->addChild(inst40);
				inst40->__scene = this;
				inst40->__timeline->clear();
				inst40->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst41 = new CocoClip(nullptr);
			inst41->__instanceName = String("Actions");
			inst36->addChild(inst41);
			inst41->__scene = this;
			inst41->__timeline->clear();
			inst41->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst41->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst41->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst41->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst42 = new CocoClip(nullptr);
		inst42->__instanceName = String("Avatar_Leonidas");
		__root->addChild(inst42);
		inst42->__scene = this;
		inst42->__timeline->clear();
		inst42->__timeline->addLabelEx(0, String("Init"));
		inst42->__timeline->addLabelEx(1, String("Enable"));
		inst42->__timeline->addLabelEx(10, String("Disable"));
		inst42->__timeline->addLabelEx(20, String("Select"));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -113, 243.96, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 34, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -113, 110, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 39, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -113, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 49, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -113, 125, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 54, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -113, 105, 0.251923, 0.256225, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/AvatarJump.ogg"), true, 1), false, false, String(""));
		inst42->__timeline->addKeyFrameEx(nullptr, nullptr, 60, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true,  -113, 125, 0.251923, 0.256225, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst43 = new CocoClip(nullptr);
			inst43->__instanceName = String("TileOnly1");
			inst42->addChild(inst43);
			inst43->__scene = this;
			inst43->__timeline->clear();
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 3.333333, 3.265306, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst43->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 4, 3.918367, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst44 = new CocoClip(Image_TileOnly);
				inst44->__instanceName = String(":: TileOnly");
				inst43->addChild(inst44);
				inst44->__scene = this;
				inst44->__timeline->clear();
				inst44->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 3.33333, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst45 = new CocoClip(nullptr);
			inst45->__instanceName = String("LeonidasAvatar");
			inst42->addChild(inst45);
			inst45->__scene = this;
			inst45->__timeline->clear();
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			inst45->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 11, 1.2, 1.2, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String("idle"));
			{
				CocoClip* inst46 = new CocoClip(Image_SpriteSymbol_LeonidasAvatar);
				inst46->__instanceName = String("AvatarIcon");
				inst45->addChild(inst46);
				inst46->__scene = this;
				inst46->__timeline->clear();
				inst46->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst47 = new CocoClip(nullptr);
			inst47->__instanceName = String("Actions");
			inst42->addChild(inst47);
			inst47->__scene = this;
			inst47->__timeline->clear();
			inst47->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst47->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst47->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst47->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst48 = new CocoClip(nullptr);
		inst48->__instanceName = String("Clouds");
		__root->addChild(inst48);
		inst48->__scene = this;
		inst48->__timeline->clear();
		inst48->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -407.5,  -114.75, 1, 1, 0,  -407.5,  -114.75, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst49 = new CocoClip(nullptr);
			inst49->__instanceName = String("cloud21");
			inst48->addChild(inst49);
			inst49->__scene = this;
			inst49->__timeline->clear();
			inst49->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -388.5,  -110, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst49->__timeline->addKeyFrameEx(nullptr, nullptr, 1600, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 388.5,  -149, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst50 = new CocoClip(Image_ImageSymbol_cloud2);
				inst50->__instanceName = String(":: cloud2");
				inst49->addChild(inst50);
				inst50->__scene = this;
				inst50->__timeline->clear();
				inst50->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst51 = new CocoClip(nullptr);
			inst51->__instanceName = String("cloud51");
			inst48->addChild(inst51);
			inst51->__scene = this;
			inst51->__timeline->clear();
			inst51->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -470.5,  -136, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst51->__timeline->addKeyFrameEx(nullptr, nullptr, 1280, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 344.5,  -194, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst52 = new CocoClip(Image_ImageSymbol_cloud5);
				inst52->__instanceName = String(":: cloud5");
				inst51->addChild(inst52);
				inst52->__scene = this;
				inst52->__timeline->clear();
				inst52->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
		}
		CocoClip* inst53 = new CocoClip(nullptr);
		inst53->__instanceName = String("Leonidas");
		__root->addChild(inst53);
		inst53->__scene = this;
		inst53->__timeline->clear();
		inst53->__timeline->addLabelEx(1, String("Animate"));
		inst53->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -186.4136,  -58.01581, 0.7, 0.7, 0,  -156.3051,  -42.16545, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst54 = new CocoClip(nullptr);
			inst54->__instanceName = String("inst1_LEONIDAS_hand");
			inst53->addChild(inst54);
			inst54->__scene = this;
			inst54->__timeline->clear();
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -114.5,  -51.5, 1.437208, 1.434288, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 22, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -114.5,  -50.5, 1.437208, 1.434288, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 27, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -114.5,  -70.6, 1.437208, 1.434288,  -21.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 31, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -114.5,  -50.5, 1.437208, 1.434288, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -114.5,  -70.6, 1.437208, 1.434288,  -21.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 40, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -114.5,  -50.5, 1.437208, 1.434288, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst54->__timeline->addKeyFrameEx(nullptr, nullptr, 71, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -114.5,  -51.5, 1.437208, 1.434288, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst55 = new CocoClip(Image_LEONIDAS_hand);
				inst55->__instanceName = String(":: LEONIDAS_hand");
				inst54->addChild(inst55);
				inst55->__scene = this;
				inst55->__timeline->clear();
				inst55->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst56 = new CocoClip(nullptr);
			inst56->__instanceName = String("inst1_LEONIDAS_body");
			inst53->addChild(inst56);
			inst56->__scene = this;
			inst56->__timeline->clear();
			inst56->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -162.6429,  -19.21429, 1.428571, 1.263636, 0, 52.85714,  -30.71429, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst56->__timeline->addKeyFrameEx(nullptr, nullptr, 22, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -162.6429,  -19.21429, 1.428571, 1.263636, 0, 52.85714,  -30.71429, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst56->__timeline->addKeyFrameEx(nullptr, nullptr, 27, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -162.6429,  -29.21429, 1.428571, 1.427909, 0, 52.85714,  -30.71429, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst56->__timeline->addKeyFrameEx(nullptr, nullptr, 31, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -162.6429,  -19.21429, 1.428571, 1.263636, 0, 52.85714,  -30.71429, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst56->__timeline->addKeyFrameEx(nullptr, nullptr, 71, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -162.6429,  -19.21429, 1.428571, 1.263636, 0, 52.85714,  -30.71429, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst57 = new CocoClip(Image_LEONIDAS_body);
				inst57->__instanceName = String(":: LEONIDAS_body");
				inst56->addChild(inst57);
				inst57->__scene = this;
				inst57->__timeline->clear();
				inst57->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 50.5,  -31.39999, 0.3, 0.3, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst58 = new CocoClip(Image_SpriteSymbol_LeonidasClipHead2);
			inst58->__instanceName = String("LeonidasClipHead21");
			inst53->addChild(inst58);
			inst58->__scene = this;
			inst58->__timeline->clear();
			inst58->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -142.25,  -76.75, 0.7, 0.7, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst58->__timeline->addKeyFrameEx(nullptr, nullptr, 22, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -142.25,  -76.75, 0.7, 0.7, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst58->__timeline->addKeyFrameEx(nullptr, nullptr, 27, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -142.25,  -92.75, 0.7, 0.7, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst58->__timeline->addKeyFrameEx(nullptr, nullptr, 31, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -142.25,  -76.75, 0.7, 0.7, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst58->__timeline->addKeyFrameEx(nullptr, nullptr, 71, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -142.25,  -76.75, 0.7, 0.7, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			CocoClip* inst59 = new CocoClip(nullptr);
			inst59->__instanceName = String("Actions");
			inst53->addChild(inst59);
			inst59->__scene = this;
			inst59->__timeline->clear();
			inst59->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst60 = new CocoClip(nullptr);
		inst60->__instanceName = String("Xerxes");
		__root->addChild(inst60);
		inst60->__scene = this;
		inst60->__timeline->clear();
		inst60->__timeline->addLabelEx(1, String("Animate"));
		inst60->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 203.85,  -53.55503, 0.7, 0.7, 0, 190.5,  -3.650044, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst61 = new CocoClip(nullptr);
			inst61->__instanceName = String("inst1_Xerxes_Sleeve");
			inst60->addChild(inst61);
			inst61->__scene = this;
			inst61->__timeline->clear();
			inst61->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 170.1,  -29.1, 1.458334, 1.454545, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst61->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 170.1,  -35.1, 1.458334, 1.454545, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst61->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 170.1,  -29.1, 1.458334, 1.454545, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst61->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 170.1,  -29.1, 1.458334, 1.454545, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst62 = new CocoClip(Image_Xerxes_Sleeve);
				inst62->__instanceName = String(":: Xerxes_Sleeve");
				inst61->addChild(inst62);
				inst62->__scene = this;
				inst62->__timeline->clear();
				inst62->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst63 = new CocoClip(nullptr);
			inst63->__instanceName = String("inst1_XERXES_hand");
			inst60->addChild(inst63);
			inst63->__scene = this;
			inst63->__timeline->clear();
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 163.25,  -23, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 164.25,  -28, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 163.25,  -23, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 37, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 161.25,  -30, 1.428571, 1.399999, 35.7, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 44, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 163.25,  -23, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 51, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 161.25,  -30, 1.428571, 1.399999, 35.7, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 59, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 163.25,  -23, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst63->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 163.25,  -23, 1.428571, 1.399999, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst64 = new CocoClip(Image_XERXES_hand);
				inst64->__instanceName = String(":: XERXES_hand");
				inst63->addChild(inst64);
				inst64->__scene = this;
				inst64->__timeline->clear();
				inst64->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst65 = new CocoClip(nullptr);
			inst65->__instanceName = String("inst1_XERXES_Body");
			inst60->addChild(inst65);
			inst65->__scene = this;
			inst65->__timeline->clear();
			inst65->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 190.5, 2.5, 1.426472, 1.343136, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst65->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 190.5,  -1.5, 1.426472, 1.423725, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst65->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 190.5, 2.5, 1.426472, 1.343136, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst65->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 190.5, 2.5, 1.426472, 1.343136, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst66 = new CocoClip(Image_XERXES_Body);
				inst66->__instanceName = String(":: XERXES_Body");
				inst65->addChild(inst66);
				inst66->__scene = this;
				inst66->__timeline->clear();
				inst66->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst67 = new CocoClip(nullptr);
			inst67->__instanceName = String("inst1_XerxesClipHead2");
			inst60->addChild(inst67);
			inst67->__scene = this;
			inst67->__timeline->clear();
			inst67->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 184.8,  -55.8, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst67->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 184.8,  -62.8, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst67->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 184.8,  -55.8, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst67->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 184.8,  -55.8, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst68 = new CocoClip(Image_XerxesClipHead2);
				inst68->__instanceName = String(":: XerxesClipHead2");
				inst67->addChild(inst68);
				inst68->__scene = this;
				inst68->__timeline->clear();
				inst68->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst69 = new CocoClip(nullptr);
			inst69->__instanceName = String("Actions");
			inst60->addChild(inst69);
			inst69->__scene = this;
			inst69->__timeline->clear();
			inst69->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst70 = new CocoClip(nullptr);
		inst70->__instanceName = String("PrizeTable");
		__root->addChild(inst70);
		inst70->__scene = this;
		inst70->__timeline->clear();
		inst70->__timeline->addLabelEx(1, String("Show"));
		inst70->__timeline->addKeyFrameEx(nullptr, nullptr, 49, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -192, 40, 0.4, 0.4, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst71 = new CocoClip(nullptr);
			inst71->__instanceName = String("PriceTable1");
			inst70->addChild(inst71);
			inst71->__scene = this;
			inst71->__timeline->clear();
			inst71->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.173483, 0.173043, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst71->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.493819, 2.487498, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst71->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.734831, 1.730433, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst71->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.168539, 2.163041, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst72 = new CocoClip(Image_PriceTable);
				inst72->__instanceName = String(":: PriceTable");
				inst71->addChild(inst72);
				inst72->__scene = this;
				inst72->__timeline->clear();
				inst72->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst73 = new CocoClip(nullptr);
			inst73->__instanceName = String("Actions");
			inst70->addChild(inst73);
			inst73->__scene = this;
			inst73->__timeline->clear();
			inst73->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst73->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, false, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst74 = new CocoClip(nullptr);
		inst74->__instanceName = String("OpenAllButton");
		__root->addChild(inst74);
		inst74->__scene = this;
		inst74->__timeline->clear();
		inst74->__timeline->addLabelEx(1, String("Disable"));
		inst74->__timeline->addLabelEx(13, String("Enabled"));
		inst74->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 192, 243.96, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst74->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true, 192, 125, 1, 1, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst75 = new CocoClip(nullptr);
			inst75->__instanceName = String("openunpressed1");
			inst74->addChild(inst75);
			inst75->__scene = this;
			inst75->__timeline->clear();
			inst75->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.8, nullptr, false, false, String(""));
			inst75->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst75->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.8, nullptr, false, false, String(""));
			inst75->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst76 = new CocoClip(Image_openunpressed);
				inst76->__instanceName = String(":: openunpressed");
				inst75->addChild(inst76);
				inst76->__scene = this;
				inst76->__timeline->clear();
				inst76->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst77 = new CocoClip(nullptr);
			inst77->__instanceName = String("openunpressed2");
			inst74->addChild(inst77);
			inst77->__scene = this;
			inst77->__timeline->clear();
			inst77->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst78 = new CocoClip(Image_openunpressed);
				inst78->__instanceName = String("Instance1");
				inst77->addChild(inst78);
				inst78->__scene = this;
				inst78->__timeline->clear();
				inst78->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst78->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst78->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst79 = new CocoClip(nullptr);
			inst79->__instanceName = String("Actions");
			inst74->addChild(inst79);
			inst79->__scene = this;
			inst79->__timeline->clear();
			inst79->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst79->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst80 = new CocoClip(nullptr);
		inst80->__instanceName = String("BuyTicketButton");
		__root->addChild(inst80);
		inst80->__scene = this;
		inst80->__timeline->clear();
		inst80->__timeline->addLabelEx(1, String("Disable"));
		inst80->__timeline->addLabelEx(13, String("Enabled"));
		inst80->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -192, 243.96, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst80->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, true, true,  -192, 125, 1, 1, 0, 0, 0, 3, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst81 = new CocoClip(nullptr);
			inst81->__instanceName = String("buyunpressed1");
			inst80->addChild(inst81);
			inst81->__scene = this;
			inst81->__timeline->clear();
			inst81->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.8, nullptr, false, false, String(""));
			inst81->__timeline->addKeyFrameEx(nullptr, nullptr, 1, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst81->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.8, nullptr, false, false, String(""));
			inst81->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, false, 0, 0, 0.9, 0.9, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, nullptr, false, false, String(""));
			{
				CocoClip* inst82 = new CocoClip(Image_buyunpressed);
				inst82->__instanceName = String(":: buyunpressed");
				inst81->addChild(inst82);
				inst82->__scene = this;
				inst82->__timeline->clear();
				inst82->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.55, 0.55, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst83 = new CocoClip(nullptr);
			inst83->__instanceName = String("buyunpressed2");
			inst80->addChild(inst83);
			inst83->__scene = this;
			inst83->__timeline->clear();
			inst83->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst84 = new CocoClip(Image_buyunpressed);
				inst84->__instanceName = String(":: buyunpressed");
				inst83->addChild(inst84);
				inst84->__scene = this;
				inst84->__timeline->clear();
				inst84->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst84->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.55, 0.55, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst84->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.5, 0.5, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst85 = new CocoClip(nullptr);
			inst85->__instanceName = String("inst1_ticket_price");
			inst80->addChild(inst85);
			inst85->__scene = this;
			inst85->__timeline->clear();
			inst85->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0,  -38.20996, 0.994186, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst86 = new CocoClip(Image_ticket_price);
				inst86->__instanceName = String(":: ticket_price");
				inst85->addChild(inst86);
				inst86->__scene = this;
				inst86->__timeline->clear();
				inst86->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst87 = new CocoClip(nullptr);
			inst87->__instanceName = String("Actions");
			inst80->addChild(inst87);
			inst87->__scene = this;
			inst87->__timeline->clear();
			inst87->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst87->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst88 = new CocoClip(nullptr);
		inst88->__instanceName = String("Winnings");
		__root->addChild(inst88);
		inst88->__scene = this;
		inst88->__timeline->clear();
		inst88->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 193.5,  -243, 1.005435, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst88->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 193.5,  -134, 1.005435, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst89 = new CocoClip(Image_winnings);
			inst89->__instanceName = String(":: winnings");
			inst88->addChild(inst89);
			inst89->__scene = this;
			inst89->__timeline->clear();
			inst89->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst90 = new CocoClip(nullptr);
		inst90->__instanceName = String("Balance");
		__root->addChild(inst90);
		inst90->__scene = this;
		inst90->__timeline->clear();
		inst90->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -190.5,  -243, 1.005435, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst90->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -190.5,  -134, 1.005435, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst91 = new CocoClip(Image_Balance);
			inst91->__instanceName = String(":: Balance");
			inst90->addChild(inst91);
			inst91->__scene = this;
			inst91->__timeline->clear();
			inst91->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst92 = new CocoClip(nullptr);
		inst92->__instanceName = String("Grid");
		__root->addChild(inst92);
		inst92->__scene = this;
		inst92->__timeline->clear();
		inst92->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0,  -10, 0.05, 0.05, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		inst92->__timeline->addKeyFrameEx(nullptr, nullptr, 47, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0,  -10, 0.4, 0.4,  -90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst93 = new CocoClip(nullptr);
			inst93->__instanceName = String("gridCell1");
			inst92->addChild(inst93);
			inst93->__scene = this;
			inst93->__timeline->clear();
			inst93->__timeline->addLabelEx(0, String("closed"));
			inst93->__timeline->addLabelEx(5, String("flip"));
			inst93->__timeline->addLabelEx(13, String("Winner"));
			inst93->__timeline->addLabelEx(26, String("Looser"));
			inst93->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115, 222.5, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst93->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true,  -115, 222.5, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst94 = new CocoClip(nullptr);
				inst94->__instanceName = String("Back");
				inst93->addChild(inst94);
				inst94->__scene = this;
				inst94->__timeline->clear();
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst94->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst95 = new CocoClip(Image_StoneTile_Back);
					inst95->__instanceName = String(":: StoneTile_Back");
					inst94->addChild(inst95);
					inst95->__scene = this;
					inst95->__timeline->clear();
					inst95->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst96 = new CocoClip(nullptr);
				inst96->__instanceName = String("Front");
				inst93->addChild(inst96);
				inst96->__scene = this;
				inst96->__timeline->clear();
				inst96->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst96->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst96->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst96->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst97 = new CocoClip(Image_grid_tile);
					inst97->__instanceName = String(":: grid_tile");
					inst96->addChild(inst97);
					inst97->__scene = this;
					inst97->__timeline->clear();
					inst97->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst98 = new CocoClip(nullptr);
				inst98->__instanceName = String("Actions");
				inst93->addChild(inst98);
				inst98->__scene = this;
				inst98->__timeline->clear();
				inst98->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst98->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst98->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst98->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst99 = new CocoClip(nullptr);
			inst99->__instanceName = String("gridCell2");
			inst92->addChild(inst99);
			inst99->__scene = this;
			inst99->__timeline->clear();
			inst99->__timeline->addLabelEx(0, String("closed"));
			inst99->__timeline->addLabelEx(5, String("flip"));
			inst99->__timeline->addLabelEx(13, String("Winner"));
			inst99->__timeline->addLabelEx(26, String("Looser"));
			inst99->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 205,  -75.83334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst99->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 205,  -75.83334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst100 = new CocoClip(nullptr);
				inst100->__instanceName = String("Back");
				inst99->addChild(inst100);
				inst100->__scene = this;
				inst100->__timeline->clear();
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst100->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst101 = new CocoClip(Image_StoneTile_Back);
					inst101->__instanceName = String(":: StoneTile_Back");
					inst100->addChild(inst101);
					inst101->__scene = this;
					inst101->__timeline->clear();
					inst101->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst102 = new CocoClip(nullptr);
				inst102->__instanceName = String("Front");
				inst99->addChild(inst102);
				inst102->__scene = this;
				inst102->__timeline->clear();
				inst102->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst102->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst102->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst102->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst103 = new CocoClip(Image_grid_tile);
					inst103->__instanceName = String(":: grid_tile");
					inst102->addChild(inst103);
					inst103->__scene = this;
					inst103->__timeline->clear();
					inst103->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst104 = new CocoClip(nullptr);
				inst104->__instanceName = String("Actions");
				inst99->addChild(inst104);
				inst104->__scene = this;
				inst104->__timeline->clear();
				inst104->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst104->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst104->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst104->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst105 = new CocoClip(nullptr);
			inst105->__instanceName = String("gridCell3");
			inst92->addChild(inst105);
			inst105->__scene = this;
			inst105->__timeline->clear();
			inst105->__timeline->addLabelEx(0, String("closed"));
			inst105->__timeline->addLabelEx(5, String("flip"));
			inst105->__timeline->addLabelEx(13, String("Winner"));
			inst105->__timeline->addLabelEx(26, String("Looser"));
			inst105->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 44.99999,  -225, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst105->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 44.99999,  -225, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst106 = new CocoClip(nullptr);
				inst106->__instanceName = String("Back");
				inst105->addChild(inst106);
				inst106->__scene = this;
				inst106->__timeline->clear();
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst106->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst107 = new CocoClip(Image_StoneTile_Back);
					inst107->__instanceName = String(":: StoneTile_Back");
					inst106->addChild(inst107);
					inst107->__scene = this;
					inst107->__timeline->clear();
					inst107->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst108 = new CocoClip(nullptr);
				inst108->__instanceName = String("Front");
				inst105->addChild(inst108);
				inst108->__scene = this;
				inst108->__timeline->clear();
				inst108->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst108->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst108->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst108->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst109 = new CocoClip(Image_grid_tile);
					inst109->__instanceName = String(":: grid_tile");
					inst108->addChild(inst109);
					inst109->__scene = this;
					inst109->__timeline->clear();
					inst109->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst110 = new CocoClip(nullptr);
				inst110->__instanceName = String("Actions");
				inst105->addChild(inst110);
				inst110->__scene = this;
				inst110->__timeline->clear();
				inst110->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst110->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst110->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst110->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst111 = new CocoClip(nullptr);
			inst111->__instanceName = String("gridCell4");
			inst92->addChild(inst111);
			inst111->__scene = this;
			inst111->__timeline->clear();
			inst111->__timeline->addLabelEx(0, String("closed"));
			inst111->__timeline->addLabelEx(5, String("flip"));
			inst111->__timeline->addLabelEx(13, String("Winner"));
			inst111->__timeline->addLabelEx(26, String("Looser"));
			inst111->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 205, 73.33334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst111->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 205, 73.33334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst112 = new CocoClip(nullptr);
				inst112->__instanceName = String("Back");
				inst111->addChild(inst112);
				inst112->__scene = this;
				inst112->__timeline->clear();
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst112->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst113 = new CocoClip(Image_StoneTile_Back);
					inst113->__instanceName = String(":: StoneTile_Back");
					inst112->addChild(inst113);
					inst113->__scene = this;
					inst113->__timeline->clear();
					inst113->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst114 = new CocoClip(nullptr);
				inst114->__instanceName = String("Front");
				inst111->addChild(inst114);
				inst114->__scene = this;
				inst114->__timeline->clear();
				inst114->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst114->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst114->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst114->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst115 = new CocoClip(Image_grid_tile);
					inst115->__instanceName = String(":: grid_tile");
					inst114->addChild(inst115);
					inst115->__scene = this;
					inst115->__timeline->clear();
					inst115->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst116 = new CocoClip(nullptr);
				inst116->__instanceName = String("Actions");
				inst111->addChild(inst116);
				inst116->__scene = this;
				inst116->__timeline->clear();
				inst116->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst116->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst116->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst116->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst117 = new CocoClip(nullptr);
			inst117->__instanceName = String("gridCell5");
			inst92->addChild(inst117);
			inst117->__scene = this;
			inst117->__timeline->clear();
			inst117->__timeline->addLabelEx(0, String("closed"));
			inst117->__timeline->addLabelEx(5, String("flip"));
			inst117->__timeline->addLabelEx(13, String("Winner"));
			inst117->__timeline->addLabelEx(26, String("Looser"));
			inst117->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 44.99999,  -75.83334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst117->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 44.99999,  -75.83334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst118 = new CocoClip(nullptr);
				inst118->__instanceName = String("Back");
				inst117->addChild(inst118);
				inst118->__scene = this;
				inst118->__timeline->clear();
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst118->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst119 = new CocoClip(Image_StoneTile_Back);
					inst119->__instanceName = String(":: StoneTile_Back");
					inst118->addChild(inst119);
					inst119->__scene = this;
					inst119->__timeline->clear();
					inst119->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst120 = new CocoClip(nullptr);
				inst120->__instanceName = String("Front");
				inst117->addChild(inst120);
				inst120->__scene = this;
				inst120->__timeline->clear();
				inst120->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst120->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst120->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst120->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst121 = new CocoClip(Image_grid_tile);
					inst121->__instanceName = String(":: grid_tile");
					inst120->addChild(inst121);
					inst121->__scene = this;
					inst121->__timeline->clear();
					inst121->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst122 = new CocoClip(nullptr);
				inst122->__instanceName = String("Actions");
				inst117->addChild(inst122);
				inst122->__scene = this;
				inst122->__timeline->clear();
				inst122->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst122->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst122->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst122->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst123 = new CocoClip(nullptr);
			inst123->__instanceName = String("gridCell6");
			inst92->addChild(inst123);
			inst123->__scene = this;
			inst123->__timeline->clear();
			inst123->__timeline->addLabelEx(0, String("closed"));
			inst123->__timeline->addLabelEx(5, String("flip"));
			inst123->__timeline->addLabelEx(13, String("Winner"));
			inst123->__timeline->addLabelEx(26, String("Looser"));
			inst123->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115,  -225, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst123->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true,  -115,  -225, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst124 = new CocoClip(nullptr);
				inst124->__instanceName = String("Back");
				inst123->addChild(inst124);
				inst124->__scene = this;
				inst124->__timeline->clear();
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst124->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst125 = new CocoClip(Image_StoneTile_Back);
					inst125->__instanceName = String(":: StoneTile_Back");
					inst124->addChild(inst125);
					inst125->__scene = this;
					inst125->__timeline->clear();
					inst125->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst126 = new CocoClip(nullptr);
				inst126->__instanceName = String("Front");
				inst123->addChild(inst126);
				inst126->__scene = this;
				inst126->__timeline->clear();
				inst126->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst126->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst126->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst126->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst127 = new CocoClip(Image_grid_tile);
					inst127->__instanceName = String(":: grid_tile");
					inst126->addChild(inst127);
					inst127->__scene = this;
					inst127->__timeline->clear();
					inst127->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst128 = new CocoClip(nullptr);
				inst128->__instanceName = String("Actions");
				inst123->addChild(inst128);
				inst128->__scene = this;
				inst128->__timeline->clear();
				inst128->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst128->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst128->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst128->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst129 = new CocoClip(nullptr);
			inst129->__instanceName = String("gridCell7");
			inst92->addChild(inst129);
			inst129->__scene = this;
			inst129->__timeline->clear();
			inst129->__timeline->addLabelEx(0, String("closed"));
			inst129->__timeline->addLabelEx(5, String("flip"));
			inst129->__timeline->addLabelEx(13, String("Winner"));
			inst129->__timeline->addLabelEx(26, String("Looser"));
			inst129->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 205, 222.5, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst129->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 205, 222.5, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst130 = new CocoClip(nullptr);
				inst130->__instanceName = String("Back");
				inst129->addChild(inst130);
				inst130->__scene = this;
				inst130->__timeline->clear();
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst130->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst131 = new CocoClip(Image_StoneTile_Back);
					inst131->__instanceName = String(":: StoneTile_Back");
					inst130->addChild(inst131);
					inst131->__scene = this;
					inst131->__timeline->clear();
					inst131->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst132 = new CocoClip(nullptr);
				inst132->__instanceName = String("Front");
				inst129->addChild(inst132);
				inst132->__scene = this;
				inst132->__timeline->clear();
				inst132->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst132->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst132->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst132->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst133 = new CocoClip(Image_grid_tile);
					inst133->__instanceName = String(":: grid_tile");
					inst132->addChild(inst133);
					inst133->__scene = this;
					inst133->__timeline->clear();
					inst133->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst134 = new CocoClip(nullptr);
				inst134->__instanceName = String("Actions");
				inst129->addChild(inst134);
				inst134->__scene = this;
				inst134->__timeline->clear();
				inst134->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst134->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst134->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst134->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst135 = new CocoClip(nullptr);
			inst135->__instanceName = String("gridCell8");
			inst92->addChild(inst135);
			inst135->__scene = this;
			inst135->__timeline->clear();
			inst135->__timeline->addLabelEx(0, String("closed"));
			inst135->__timeline->addLabelEx(5, String("flip"));
			inst135->__timeline->addLabelEx(13, String("Winner"));
			inst135->__timeline->addLabelEx(26, String("Looser"));
			inst135->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 44.99999, 73.33334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst135->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 44.99999, 73.33334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst136 = new CocoClip(nullptr);
				inst136->__instanceName = String("Back");
				inst135->addChild(inst136);
				inst136->__scene = this;
				inst136->__timeline->clear();
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst136->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst137 = new CocoClip(Image_StoneTile_Back);
					inst137->__instanceName = String(":: StoneTile_Back");
					inst136->addChild(inst137);
					inst137->__scene = this;
					inst137->__timeline->clear();
					inst137->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst138 = new CocoClip(nullptr);
				inst138->__instanceName = String("Front");
				inst135->addChild(inst138);
				inst138->__scene = this;
				inst138->__timeline->clear();
				inst138->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst138->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst138->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst138->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst139 = new CocoClip(Image_grid_tile);
					inst139->__instanceName = String(":: grid_tile");
					inst138->addChild(inst139);
					inst139->__scene = this;
					inst139->__timeline->clear();
					inst139->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst140 = new CocoClip(nullptr);
				inst140->__instanceName = String("Actions");
				inst135->addChild(inst140);
				inst140->__scene = this;
				inst140->__timeline->clear();
				inst140->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst140->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst140->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst140->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst141 = new CocoClip(nullptr);
			inst141->__instanceName = String("gridCell9");
			inst92->addChild(inst141);
			inst141->__scene = this;
			inst141->__timeline->clear();
			inst141->__timeline->addLabelEx(0, String("closed"));
			inst141->__timeline->addLabelEx(5, String("flip"));
			inst141->__timeline->addLabelEx(13, String("Winner"));
			inst141->__timeline->addLabelEx(26, String("Looser"));
			inst141->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115,  -75.83334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst141->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true,  -115,  -75.83334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst142 = new CocoClip(nullptr);
				inst142->__instanceName = String("Back");
				inst141->addChild(inst142);
				inst142->__scene = this;
				inst142->__timeline->clear();
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst142->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst143 = new CocoClip(Image_StoneTile_Back);
					inst143->__instanceName = String(":: StoneTile_Back");
					inst142->addChild(inst143);
					inst143->__scene = this;
					inst143->__timeline->clear();
					inst143->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst144 = new CocoClip(nullptr);
				inst144->__instanceName = String("Front");
				inst141->addChild(inst144);
				inst144->__scene = this;
				inst144->__timeline->clear();
				inst144->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst144->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst144->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst144->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst145 = new CocoClip(Image_grid_tile);
					inst145->__instanceName = String(":: grid_tile");
					inst144->addChild(inst145);
					inst145->__scene = this;
					inst145->__timeline->clear();
					inst145->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst146 = new CocoClip(nullptr);
				inst146->__instanceName = String("Actions");
				inst141->addChild(inst146);
				inst146->__scene = this;
				inst146->__timeline->clear();
				inst146->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst146->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst146->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst146->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst147 = new CocoClip(nullptr);
			inst147->__instanceName = String("gridCell10");
			inst92->addChild(inst147);
			inst147->__scene = this;
			inst147->__timeline->clear();
			inst147->__timeline->addLabelEx(0, String("closed"));
			inst147->__timeline->addLabelEx(5, String("flip"));
			inst147->__timeline->addLabelEx(13, String("Winner"));
			inst147->__timeline->addLabelEx(26, String("Looser"));
			inst147->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 44.99999, 222.5, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst147->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 44.99999, 222.5, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst148 = new CocoClip(nullptr);
				inst148->__instanceName = String("Back");
				inst147->addChild(inst148);
				inst148->__scene = this;
				inst148->__timeline->clear();
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst148->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst149 = new CocoClip(Image_StoneTile_Back);
					inst149->__instanceName = String(":: StoneTile_Back");
					inst148->addChild(inst149);
					inst149->__scene = this;
					inst149->__timeline->clear();
					inst149->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst150 = new CocoClip(nullptr);
				inst150->__instanceName = String("Front");
				inst147->addChild(inst150);
				inst150->__scene = this;
				inst150->__timeline->clear();
				inst150->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst150->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst150->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst150->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst151 = new CocoClip(Image_grid_tile);
					inst151->__instanceName = String(":: grid_tile");
					inst150->addChild(inst151);
					inst151->__scene = this;
					inst151->__timeline->clear();
					inst151->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst152 = new CocoClip(nullptr);
				inst152->__instanceName = String("Actions");
				inst147->addChild(inst152);
				inst152->__scene = this;
				inst152->__timeline->clear();
				inst152->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst152->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst152->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst152->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst153 = new CocoClip(nullptr);
			inst153->__instanceName = String("gridCell11");
			inst92->addChild(inst153);
			inst153->__scene = this;
			inst153->__timeline->clear();
			inst153->__timeline->addLabelEx(0, String("closed"));
			inst153->__timeline->addLabelEx(5, String("flip"));
			inst153->__timeline->addLabelEx(13, String("Winner"));
			inst153->__timeline->addLabelEx(26, String("Looser"));
			inst153->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115, 73.33334, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst153->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true,  -115, 73.33334, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst154 = new CocoClip(nullptr);
				inst154->__instanceName = String("Back");
				inst153->addChild(inst154);
				inst154->__scene = this;
				inst154->__timeline->clear();
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst154->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst155 = new CocoClip(Image_StoneTile_Back);
					inst155->__instanceName = String(":: StoneTile_Back");
					inst154->addChild(inst155);
					inst155->__scene = this;
					inst155->__timeline->clear();
					inst155->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst156 = new CocoClip(nullptr);
				inst156->__instanceName = String("Front");
				inst153->addChild(inst156);
				inst156->__scene = this;
				inst156->__timeline->clear();
				inst156->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst156->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst156->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst156->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst157 = new CocoClip(Image_grid_tile);
					inst157->__instanceName = String(":: grid_tile");
					inst156->addChild(inst157);
					inst157->__scene = this;
					inst157->__timeline->clear();
					inst157->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst158 = new CocoClip(nullptr);
				inst158->__instanceName = String("Actions");
				inst153->addChild(inst158);
				inst158->__scene = this;
				inst158->__timeline->clear();
				inst158->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst158->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst158->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst158->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst159 = new CocoClip(nullptr);
			inst159->__instanceName = String("gridCell12");
			inst92->addChild(inst159);
			inst159->__scene = this;
			inst159->__timeline->clear();
			inst159->__timeline->addLabelEx(0, String("closed"));
			inst159->__timeline->addLabelEx(5, String("flip"));
			inst159->__timeline->addLabelEx(13, String("Winner"));
			inst159->__timeline->addLabelEx(26, String("Looser"));
			inst159->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 205,  -225, 1, 1, 180, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst159->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, true, true, 205,  -225, 1, 1, 90, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst160 = new CocoClip(nullptr);
				inst160->__instanceName = String("Back");
				inst159->addChild(inst160);
				inst160->__scene = this;
				inst160->__timeline->clear();
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 9, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.211111, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 13, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.25, 2.25, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 26, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.111112, 2.111112, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst160->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.900001, 1.900001, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst161 = new CocoClip(Image_StoneTile_Back);
					inst161->__instanceName = String(":: StoneTile_Back");
					inst160->addChild(inst161);
					inst161->__scene = this;
					inst161->__timeline->clear();
					inst161->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst162 = new CocoClip(nullptr);
				inst162->__instanceName = String("Front");
				inst159->addChild(inst162);
				inst162->__scene = this;
				inst162->__timeline->clear();
				inst162->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst162->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 2.509435, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/GridCellOpen.ogg"), true, 1), false, false, String(""));
				inst162->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst162->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.250944, 2.509435, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst163 = new CocoClip(Image_grid_tile);
					inst163->__instanceName = String(":: grid_tile");
					inst162->addChild(inst163);
					inst163->__scene = this;
					inst163->__timeline->clear();
					inst163->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst164 = new CocoClip(nullptr);
				inst164->__instanceName = String("Actions");
				inst159->addChild(inst164);
				inst164->__scene = this;
				inst164->__timeline->clear();
				inst164->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst164->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 12, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst164->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst164->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst165 = new CocoClip(nullptr);
			inst165->__instanceName = String("Actions");
			inst92->addChild(inst165);
			inst165->__scene = this;
			inst165->__timeline->clear();
			inst165->__timeline->addKeyFrameEx(nullptr, &CocoScene::stop, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst166 = new CocoClip(nullptr);
		inst166->__instanceName = String("YouWin");
		__root->addChild(inst166);
		inst166->__scene = this;
		inst166->__timeline->clear();
		inst166->__timeline->addKeyFrameEx(nullptr, nullptr, 74, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		{
			CocoClip* inst167 = new CocoClip(nullptr);
			inst167->__instanceName = String("shinySound");
			inst166->addChild(inst167);
			inst167->__scene = this;
			inst167->__timeline->clear();
			inst167->__timeline->addKeyFrameEx(nullptr, nullptr, 55, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, new CocoAudio(String("./assets/sounds/ShinyGlittery.ogg"), true, 1), false, false, String(""));
			CocoClip* inst168 = new CocoClip(nullptr);
			inst168->__instanceName = String("WIN_Shield");
			inst166->addChild(inst168);
			inst168->__scene = this;
			inst168->__timeline->clear();
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 50, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.009356, 0.009346, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 55, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1.001065, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 61, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.74846, 0.747663, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 66, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.935575, 0.934579, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 124, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.935575, 0.934579, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst168->__timeline->addKeyFrameEx(nullptr, nullptr, 125, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, false, 0, 0, 0.935575, 0.934579, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst169 = new CocoClip(Image_ImageSymbol_WIN_Shield);
				inst169->__instanceName = String(":: WIN_Shield");
				inst168->addChild(inst169);
				inst169->__scene = this;
				inst169->__timeline->clear();
				inst169->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			}
			CocoClip* inst170 = new CocoClip(nullptr);
			inst170->__instanceName = String("AnimationClip_YouWinLogo1");
			inst166->addChild(inst170);
			inst170->__scene = this;
			inst170->__timeline->clear();
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 50, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 55, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.8, 0.8, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 61, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 66, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 124, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			inst170->__timeline->addKeyFrameEx(nullptr, nullptr, 125, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, false, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
			{
				CocoClip* inst171 = new CocoClip(nullptr);
				inst171->__instanceName = String("WIN_Logo1");
				inst170->addChild(inst171);
				inst171->__scene = this;
				inst171->__timeline->clear();
				inst171->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst171->__timeline->addKeyFrameEx(nullptr, nullptr, 60, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				{
					CocoClip* inst172 = new CocoClip(Image_ImageSymbol_WIN_Logo);
					inst172->__instanceName = String(":: WIN_Logo");
					inst171->addChild(inst172);
					inst172->__scene = this;
					inst172->__timeline->clear();
					inst172->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst173 = new CocoClip(nullptr);
				inst173->__instanceName = String("grWhiteStar1");
				inst170->addChild(inst173);
				inst173->__scene = this;
				inst173->__timeline->clear();
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -120.5,  -93, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 10, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -120.5,  -93, 0.866667, 0.866667,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 20, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -120.5,  -93, 0.466667, 0.466667, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 21, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -120.5,  -93, 0.466667, 0.466667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 52, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 118,  -100, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 57, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 118,  -100, 0.866667, 0.866667,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst173->__timeline->addKeyFrameEx(nullptr, nullptr, 60, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 118,  -100, 0.533333, 0.533333,  -110.5, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst174 = new CocoClip(Image_grWhiteStar);
					inst174->__instanceName = String(":: grWhiteStar");
					inst173->addChild(inst174);
					inst174->__scene = this;
					inst174->__timeline->clear();
					inst174->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst175 = new CocoClip(nullptr);
				inst175->__instanceName = String("grWhiteStar2");
				inst170->addChild(inst175);
				inst175->__scene = this;
				inst175->__timeline->clear();
				inst175->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115, 32, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst175->__timeline->addKeyFrameEx(nullptr, nullptr, 11, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115, 32, 0.666667, 0.666667,  -12.3, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst175->__timeline->addKeyFrameEx(nullptr, nullptr, 15, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -115, 32, 0.8, 0.8,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst175->__timeline->addKeyFrameEx(nullptr, nullptr, 19, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -115, 32, 0.466667, 0.466667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst176 = new CocoClip(Image_grWhiteStar);
					inst176->__instanceName = String(":: grWhiteStar");
					inst175->addChild(inst176);
					inst176->__scene = this;
					inst176->__timeline->clear();
					inst176->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst177 = new CocoClip(nullptr);
				inst177->__instanceName = String("grWhiteStar3");
				inst170->addChild(inst177);
				inst177->__scene = this;
				inst177->__timeline->clear();
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 18, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -16,  -95, 0.533333, 0.533333, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 21, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -16,  -95, 0.8, 0.8,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 31, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true,  -16,  -95, 0.533333, 0.533333, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 39, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 125,  -95, 0.666667, 0.666667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 44, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 125,  -98, 1, 1,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst177->__timeline->addKeyFrameEx(nullptr, nullptr, 49, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 125,  -95, 0.666667, 0.666667,  -110.5, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst178 = new CocoClip(Image_grWhiteStar);
					inst178->__instanceName = String(":: grWhiteStar");
					inst177->addChild(inst178);
					inst178->__scene = this;
					inst178->__timeline->clear();
					inst178->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
				CocoClip* inst179 = new CocoClip(nullptr);
				inst179->__instanceName = String("grWhiteStar4");
				inst170->addChild(inst179);
				inst179->__scene = this;
				inst179->__timeline->clear();
				inst179->__timeline->addKeyFrameEx(nullptr, nullptr, 29, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 7, 28, 0.533333, 0.533333, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				inst179->__timeline->addKeyFrameEx(nullptr, nullptr, 35, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 7, 25, 0.666667, 0.666667,  -110.5, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst179->__timeline->addKeyFrameEx(nullptr, nullptr, 36, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 7, 25, 0.6, 0.6,  -92, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				inst179->__timeline->addKeyFrameEx(nullptr, nullptr, 40, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 7, 25, 0.466667, 0.466667, 0, 0, 0, 0, 1, 1, 1, 0, nullptr, false, false, String(""));
				{
					CocoClip* inst180 = new CocoClip(Image_grWhiteStar);
					inst180->__instanceName = String(":: grWhiteStar");
					inst179->addChild(inst180);
					inst180->__scene = this;
					inst180->__timeline->clear();
					inst180->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
				}
			}
			CocoClip* inst181 = new CocoClip(nullptr);
			inst181->__instanceName = String("Actions");
			inst166->addChild(inst181);
			inst181->__scene = this;
			inst181->__timeline->clear();
			inst181->__timeline->addKeyFrameEx(((GameEngine*)engine)->STATE_JUMPING_AVATARS, nullptr, 125, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
		}
		CocoClip* inst182 = new CocoClip(nullptr);
		inst182->__instanceName = String("Actions");
		__root->addChild(inst182);
		inst182->__scene = this;
		inst182->__timeline->clear();
		inst182->__timeline->addKeyFrameEx(((GameEngine*)engine)->STATE_GAME_BOARD_CHOOSE_AVATAR, nullptr, 71, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_NONE, false, true, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, String(""));
	}
}