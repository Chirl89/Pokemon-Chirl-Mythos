.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "¡{PLAYER}!\p"
	.string "¿Qué haces aquí?\p"
	.string "¡Mi ayudante te está esperando\n"
	.string "en CIUDAD MALVALONA!$"
NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "¡Será mejor no tocarlo!$"
NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM: ¡{PLAYER}! ¡Por fin llegas!\p"
	.string "Quería pedirte un favor.\p"
	.string "Verás, estoy investigando algo\n"
	.string "nuevo sobre los POKéMON. Me\l"
	.string "preguntaba si podrías echarme\l"
	.string "una mano, {PLAYER}.\p"
	.string "Te explico…\p"
	.string "Estoy escribiendo un informe que\n"
	.string "quiero presentar en una conferencia.\p"
	.string "Pero aún hay cosas que se me\n"
	.string "escapan.\p"
	.string "¡Por eso!\p"
	.string "Me gustaría que entrenases a un\n"
	.string "POKéMON que capturé hace poco.$"
NewBarkTown_Lab_Text_ElmAccepted:
	.string "¡Gracias, {PLAYER}!\n"
	.string "¡Eres de gran ayuda!$"
NewBarkTown_Lab_Text_ElmRefused:
	.string "Pero… ¡Por favor, necesito tu\n"
	.string "ayuda!$"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Cuando anuncie mis descubrimientos,\n"
	.string "¡seguro que desvelaremos aún más\l"
	.string "misterios sobre los POKéMON!$"
NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "¡Oh, vaya! ¡He recibido un correo!\p"
	.string "… … … … … … … …\n"
	.string "Hum… Ya veo…\p"
	.string "Entendido…$"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Oye, escucha.\p"
	.string "Tengo un conocido al que todos\n"
	.string "llaman SR. POKéMON.\p"
	.string "Siempre está encontrando cosas raras\n"
	.string "y presumiendo de sus descubrimientos.\p"
	.string "Pues bien, me acaba de enviar un correo\n"
	.string "diciendo que esta vez va en serio.\p"
	.string "Es muy intrigante, pero nosotros estamos\n"
	.string "hasta arriba con nuestras investigaciones...\p"
	.string "¡Espera!\n"
	.string "¡Ya lo tengo!\p"
	.string "{PLAYER}, ¿podrías ir tú en\n"
	.string "nuestro lugar?$"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Quiero que entrenes a uno de los\n"
	.string "POKéMON que hay en estas BALLS.\p"
	.string "¡Serás su primer compañero,\n"
	.string "{PLAYER}!\p"
	.string "¡Adelante, elige uno!$"
NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ELM: ¡Espera! ¿Adónde vas?$"
NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ELM: ¿Te quedas con {STR_VAR_1},\n"
	.string "el POKéMON de tipo {STR_VAR_2}?$"
NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ELM: ¿Quieres a {STR_VAR_1},\n"
	.string "el POKéMON de tipo {STR_VAR_2}?$"
NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ELM: ¿Así que te gusta {STR_VAR_1},\n"
	.string "el POKéMON de tipo {STR_VAR_2}?$"
NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ELM: Piénsatelo con calma.\p"
	.string "Elegir compañero es una decisión\n"
	.string "muy importante.$"
NewBarkTown_Lab_Text_ChoseStarter:
	.string "ELM: ¡A mí también me parece un\n"
	.string "POKéMON magnífico!$"
NewBarkTown_Lab_Text_ReceivedStarter:
	.string "¡{PLAYER} recibió a {STR_VAR_1}!$"
NewBarkTown_Lab_Text_Nickname:
	.string "¿Quieres ponerle un mote a\n"
	.string "{STR_VAR_1}?$"
NewBarkTown_Lab_Text_ElmDirections1:
	.string "El SR. POKéMON vive un poco más allá\n"
	.string "de CIUDAD CEREZO, la ciudad vecina.\p"
	.string "Es prácticamente en línea recta,\n"
	.string "así que no tiene pérdida.\p"
	.string "Pero por si acaso, tienes mi número\n"
	.string "de teléfono. ¡Llámame si pasa algo!$"
NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "El SR. POKéMON vive un poco más allá\n"
	.string "de CIUDAD CEREZO, la ciudad vecina.\p"
	.string "Es prácticamente en línea recta,\n"
	.string "así que no tiene pérdida.\p"
	.string "Espera, deja que registre mi número\n"
	.string "en tu POKéGEAR.$"
NewBarkTown_Lab_Text_RegisteredElm:
	.string "Se registró al PROF. ELM en el\n"
	.string "POKéGEAR.$"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si aparece un POKéMON salvaje,\n"
	.string "¡haz que tu POKéMON luche contra él!$"
NewBarkTown_Lab_Text_ElmDirections2:
	.string "El SR. POKéMON vive un poco más allá\n"
	.string "de CIUDAD CEREZO, la ciudad vecina.\p"
	.string "¡Cuídate mucho!$"
NewBarkTown_Lab_Text_GotElmsNumber:
	.string "¡Ya tienes mi número! ¡Llámame\n"
	.string "si pasa cualquier cosa!$"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "El SR. POKéMON vive un poco más allá\n"
	.string "de CIUDAD CEREZO, la siguiente ciudad.\p"
	.string "Es casi una ruta directa, no tiene pérdida.\p"
	.string "Pero por si acaso, toma mi número de\n"
	.string "teléfono. ¡Llámame si surge algo!$"
NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Contiene un POKéMON capturado por\n"
	.string "el PROF. ELM.$"
@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ELM: ¡{PLAYER}! ¡Es terrible!\p"
	.string "¡Nos han robado un POKéMON!\p"
	.string "¿Cómo ha podido pasar esto?$"
NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "ELM: ¿Qué decía el SR. POKéMON?$"
NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "¡{PLAYER} le entregó el HUEVO\n"
	.string "MISTERIOSO al PROF. ELM!$"
NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "ELM: ¿Esto es...? ¿Un HUEVO POKéMON?\p"
	.string "Si es así, ¡es un descubrimiento\n"
	.string "asombroso!\p"
	.string "¿Qué? ¿El PROF. OAK te dio una\n"
	.string "POKéDEX?\p"
	.string "¡{PLAYER}, eso es increíble!\p"
	.string "El PROF. OAK tiene un ojo clínico para\n"
	.string "ver el potencial de los ENTRENADORES.\p"
	.string "¡Tienes madera para llegar a la cima\n"
	.string "de la LIGA POKéMON!\p"
	.string "Deberías desafiar a los LÍDERES DE\n"
	.string "GIMNASIO de JOHTO.\p"
	.string "El más cercano está en\n"
	.string "CIUDAD MALVALONA.$"
NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ELM: ¡Sigo investigando el HUEVO!\n"
	.string "Te avisaré si descubro algo.$"
NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ELM: ¡{PLAYER}!\p"
	.string "¿Te has cruzado con mi ayudante?\n"
	.string "Te estaba buscando con el HUEVO.$"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ELM: ¡{PLAYER}!\n"
	.string "¿Cómo va ese HUEVO? ¿Ha eclosionado?\p"
	.string "¡Trátalo con mucho cariño!$"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "ELM: ¡{PLAYER}!\n"
	.string "¿Ha eclosionado el HUEVO?\p"
	.string "¡Quiero ver a ese POKéMON!$"
NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ELM: ¡{PLAYER}! ¡Ese POKéMON!\n"
	.string "¡Eclosionó del HUEVO!\p"
	.string "¡Es fascinante!$"
NewBarkTown_Lab_Text_ShowTogepi2:
	.string "¡Sabía que los POKéMON nacían\n"
	.string "de HUEVOS!\p"
	.string "¡Gracias por ayudarme con mi\n"
	.string "investigación, {PLAYER}!$"
NewBarkTown_Lab_Text_ShowTogepi3:
	.string "Toma, quiero que tengas esto como\n"
	.string "muestra de mi agradecimiento.$"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Es una PIEDRAETERNA.\p"
	.string "Si un POKéMON la lleva equipada,\n"
	.string "no evolucionará.$"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "ELM: ¡Sigue con tu viaje, {PLAYER}!\n"
	.string "¡Confío en ti!$"
NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM: ¡Te llamaré si descubro algo\n"
	.string "más!$"
NewBarkTown_Lab_Text_AideAfterTheft:
	.string "¡Fue horrible!\n"
	.string "Entró un chico pelirrojo y se llevó\l"
	.string "uno de los POKéMON.$"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM: ¡{PLAYER}! ¡Has ganado las 8\n"
	.string "MEDALLAS de GIMNASIO de JOHTO!\p"
	.string "¡Es un logro impresionante!\p"
	.string "Toma esto, te será muy útil en\n"
	.string "la LIGA POKéMON.$"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "¡Es la MASTER BALL definitiva!\n"
	.string "¡Atrapa a cualquier POKéMON sin fallar!$"
NewBarkTown_Lab_Text_KimonoGirls:
	.string "ELM: Las CHICAS EN KIMONO te están\n"
	.string "buscando en CIUDAD IRIS.$"
NewBarkTown_Lab_Text_KimonoWaiting:
	.string "Parece que algo importante está a punto\n"
	.string "de suceder en CIUDAD IRIS.$"
NewBarkTown_Lab_Text_League:
	.string "ELM: ¡{PLAYER}! ¡Dirígete a la\n"
	.string "MESETA AÑIL a través de la RUTA 27!\p"
	.string "¡Demuestra todo lo que has aprendido!$"
NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM: ¡{PLAYER}! ¡Felicidades por\n"
	.string "convertirte en CAMPEÓN!\p"
	.string "Toma, un billete para el S.S. AQUA.$"
NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "El barco zarpa desde el PUERTO de\n"
	.string "CIUDAD OLIVO rumbo a KANTO.$"
NewBarkTown_Lab_Text_LabMonEgg:
	.string "Es el HUEVO POKéMON que investiga\n"
	.string "el PROF. ELM.$"
NewBarkTown_Lab_Text_AideGivePotion:
	.string "¡{PLAYER}! ¡Espera un segundo!\p"
	.string "El PROF. ELM me pidió que te diera esto\n"
	.string "para ayudarte en tu camino.$"
NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "El PROF. ELM siempre está ocupado\n"
	.string "con sus investigaciones.$"
NewBarkTown_Lab_Text_AideSave:
	.string "No olvides guardar la partida a menudo\n"
	.string "desde el menú GUARDAR.$"
NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "¡Había alguien sospechoso merodeando\n"
	.string "por la ventana antes del robo!$"
NewBarkTown_Lab_Text_AideGiveBalls:
	.string "¡{PLAYER}! El PROF. ELM te manda esto.$"
NewBarkTown_Lab_Text_AideExplainBalls:
	.string "¡Son POKé BALLS! Úsalas para atrapar\n"
	.string "POKéMON salvajes y formar tu equipo.$"
NewBarkTown_Lab_Text_Officer1:
	.string "POLICÍA: ¡Alto ahí!\p"
	.string "¡Alguien ha robado un POKéMON del\n"
	.string "LABORATORIO!\p"
	.string "¿Quién eres tú?\p"
	.string "Espera... ¿Conoces al ladrón?$"
NewBarkTown_Lab_Text_Officer2_1:
	.string "¿Dices que combatiste contra un chico\n"
	.string "pelirrojo? ¿Cómo se llamaba?$"
NewBarkTown_Lab_Text_Officer2:
	.string "POLICÍA: ¿Se llamaba {RIVAL}?\n"
	.string "¡Entendido! ¡Iremos tras él!$"
NewBarkTown_Lab_Text_OfficerNo:
	.string "POLICÍA: Si recuerdas algo, ven a\n"
	.string "contárnoslo de inmediato.$"
NewBarkTown_Lab_Text_Elm_CallMe:
	.string "ELM: ¡Llámame cuando quieras si\n"
	.string "necesitas algo!$"
