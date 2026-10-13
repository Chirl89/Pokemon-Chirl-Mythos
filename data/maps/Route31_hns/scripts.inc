Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "CUEVA OSCURA…\p"
	.string "Si un POKéMON pudiera iluminarla,\n"
	.string "me pondría a explorarla.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "He atrapado un montón de POKéMON.\n"
	.string "¡Luchemos!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "¡Ooooh…!$"

Route31_Text_BugCatcherWade1_After:
	.string "Puedes atrapar POKéMON aunque ya\n"
	.string "lleves seis contigo.\p"
	.string "Si atrapas uno, se enviará a tu\n"
	.string "CAJA automáticamente.$"

Route31_Text_SleepyMan:
	.string "… Mmmgrr… ¿Eh?\p"
	.string "Hoy he caminado demasiado buscando\n"
	.string "POKéMON.\p"
	.string "Me duelen los pies y tengo sueño…\p"
	.string "Si fuera un POKéMON salvaje, sería\n"
	.string "facilísimo de atrapar…\p"
	.string "…Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… ¿Eh?\p"
	.string "¿Qué es eso? ¿Tienes una CARTA\n"
	.string "para mí?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "¡{PLAYER} entregó el POKéMON\n"
	.string "que llevaba la CARTA!$"

Route31_Text_ReadingMail:
	.string "A ver, a ver…\p"
	.string "Gracias por traérmela.\p"
	.string "Mi amigo es un gran tipo, ¡y tú\n"
	.string "también eres genial!\p"
	.string "¡Me gustaría darte algo a cambio!\p"
	.string "¡Ya sé! ¡Quiero que te quedes\n"
	.string "con esto!$"

Route31_Text_DescribeRest:
	.string "...Zzz...\p"
	.string "...Umm... ¡Descanso!\p"
	.string "Es la MT DESCANSO.\p"
	.string "Un movimiento con el que duermes\n"
	.string "para recuperar todos tus PS.$"

Route31_Text_WrongMail:
	.string "Esta CARTA no es para mí.$"

Route31_Text_MissingMail:
	.string "¿Por qué es tan especial este POKéMON?\p"
	.string "Si no lleva ninguna CARTA.$"

Route31_Text_DeclinedToHandOverMail:
	.string "¿Qué? ¿No quieres nada?$"

Route31_Text_CantTakeLastMon:
	.string "Si te quito ese POKéMON,\p"
	.string "¿con qué vas a combatir?$"

Route31_Text_Youngster:
	.string "Encontré un buen POKéMON en la CUEVA\n"
	.string "OSCURA.\p"
	.string "Voy a entrenarlo para enfrentarme a\n"
	.string "PEGASO.\p"
	.string "Es el líder del GIMNASIO de CIUDAD\n"
	.string "MALVALONA.$"

Route31_Text_Sign:
	.string "RUTA 31\p"
	.string "CIUDAD MALVALONA - CIUDAD CEREZO$"

Route31_Text_WadeRegister:
	.string "¡Eres increíble! ¡Me caes bien!\p"
	.string "Busco POKéMON por aquí todos los\n"
	.string "días.\p"
	.string "Entre la hierba encuentro toda clase\n"
	.string "de BAYAS.\p"
	.string "Si quieres, compartiré algunas\n"
	.string "contigo.$"

Route31_Text_WadeRematchIntro:
	.string "Te estaba esperando.\n"
	.string "¡A combatir!$"

Route31_Text_WadeRematchDefeat:
	.string "¡Ooooh…!$"

Route31_Text_WadePostRematch:
	.string "Te avisaré en cuanto encuentre algo\n"
	.string "que te pueda gustar.$"

Route31_Text_WadeHasItem:
	.string "¡Hola! ¡Te estaba buscando!\p"
	.string "Encontré algo en la hierba.\p"
	.string "¡Toma, para ti!$"

Route31_Text_WadeGaveItem:
	.string "¡Te llamaré si encuentro algo más!$"

Route31_Text_WadeNoRoom:
	.string "Vaya, parece que tu MOCHILA\n"
	.string "está llena.\p"
	.string "¡Vuelve cuando tengas sitio!$"

Route31_Text_DarkCaveSign:
	.string "CUEVA OSCURA$"
