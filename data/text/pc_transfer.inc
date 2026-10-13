gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} se envió al\n"
	.string "PC de ALGUIEN.\p"
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} se envió al\n"
#if IS_FRLG || IS_HNS
	.string "PC de BILL.\p"
#else
	.string "PC de AREDIA.\p"
#endif
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "La CAJA “{STR_VAR_3}” del\n"
	.string "PC de ALGUIEN estaba llena.\p"
	.string "{STR_VAR_2} se envió a la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "La CAJA “{STR_VAR_3}” del\n"
#if IS_FRLG || IS_HNS
	.string "PC de BILL estaba llena.\p"
#else
	.string "PC de AREDIA estaba llena.\p"
#endif
	.string "{STR_VAR_2} se envió a la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} se envió al\n"
	.string "PC de {B_PC_CREATOR_NAME}.\p"
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "¡{PLAYER} obtuvo\n"
	.string "a {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "¡No cabe ni un POKéMON más!\p"
	.string "¡Las CAJAS de POKéMON están llenas y\n"
	.string "no admiten ninguno más!$"

gText_NicknameThisPokemon::
	.string "¿Quieres ponerle un mote a\n"
	.string "{STR_VAR_1}?$"
