import re

path = "src/battle_message.c"
with open(path, "r", encoding="utf-8") as f:
    c = f.read()

replacements = {
    # Stat names
    'sText_HP,': 'sText_HP,',
    'static const u8 sText_Attack[] = _("ATTACK");': 'static const u8 sText_Attack[] = _("ATAQUE");',
    'static const u8 sText_Defense[] = _("DEFENSE");': 'static const u8 sText_Defense[] = _("DEFENSA");',
    'static const u8 sText_Speed[] = _("SPEED");': 'static const u8 sText_Speed[] = _("VELOCIDAD");',
    'static const u8 sText_SpAttack[] = _("SP. ATK");': 'static const u8 sText_SpAttack[] = _("AT. ESP.");',
    'static const u8 sText_SpDefense[] = _("SP. DEF");': 'static const u8 sText_SpDefense[] = _("DEF. ESP.");',
    'static const u8 sText_Accuracy[] = _("accuracy");': 'static const u8 sText_Accuracy[] = _("precisión");',
    'static const u8 sText_Evasiveness[] = _("evasiveness");': 'static const u8 sText_Evasiveness[] = _("evasión");',

    # Prefixes
    'static const u8 sText_WildPkmnPrefix[] = _("The wild ");': 'static const u8 sText_WildPkmnPrefix[] = _("El ");',
    'static const u8 sText_FoePkmnPrefix[] = _("The opposing ");': 'static const u8 sText_FoePkmnPrefix[] = _("El rival ");',
    'static const u8 sText_WildPkmnPrefixLower[] = _("the wild ");': 'static const u8 sText_WildPkmnPrefixLower[] = _("el ");',
    'static const u8 sText_FoePkmnPrefixLower[] = _("the opposing ");': 'static const u8 sText_FoePkmnPrefixLower[] = _("el rival ");',

    # Battle start / encounters
    'static const u8 sText_Trainer1WantsToBattle[] = _("You are challenged by {B_TRAINER1_NAME_WITH_CLASS}!\\p");': 'static const u8 sText_Trainer1WantsToBattle[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} te desafía!\\p");',
    'static const u8 sText_WildPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\\p");': 'static const u8 sText_WildPkmnAppeared[] = _("¡Apareció un {B_OPPONENT_MON1_NAME} salvaje!\\p");',
    'static const u8 sText_LegendaryPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\\p");': 'static const u8 sText_LegendaryPkmnAppeared[] = _("¡Apareció un {B_OPPONENT_MON1_NAME} salvaje!\\p");',
    'static const u8 sText_TwoWildPkmnAppeared[] = _("Oh! A wild {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME} appeared!\\p");': 'static const u8 sText_TwoWildPkmnAppeared[] = _("¡Aparecieron {B_OPPONENT_MON1_NAME} y {B_OPPONENT_MON2_NAME} salvajes!\\p");',
    'static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME}!");': 'static const u8 sText_Trainer1SentOutPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} envió a {B_OPPONENT_MON1_NAME}!");',
    'static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");': 'static const u8 sText_Trainer1SentOutTwoPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} envió a {B_OPPONENT_MON1_NAME} y a {B_OPPONENT_MON2_NAME}!");',

    # Player send out / recall
    'static const u8 sText_GoPkmn[] = _("Go! {B_PLAYER_MON1_NAME}!");': 'static const u8 sText_GoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME}!");',
    'static const u8 sText_GoTwoPkmn[] = _("Go! {B_PLAYER_MON1_NAME} and {B_PLAYER_MON2_NAME}!");': 'static const u8 sText_GoTwoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME} y {B_PLAYER_MON2_NAME}!");',
    'static const u8 sText_GoPkmn2[] = _("Go! {B_BUFF1}!");': 'static const u8 sText_GoPkmn2[] = _("¡Adelante, {B_BUFF1}!");',
    'static const u8 sText_DoItPkmn[] = _("You\'re in charge, {B_BUFF1}!");': 'static const u8 sText_DoItPkmn[] = _("¡Te toca, {B_BUFF1}!");',
    'static const u8 sText_GoForItPkmn[] = _("Go for it, {B_BUFF1}!");': 'static const u8 sText_GoForItPkmn[] = _("¡A por ellos, {B_BUFF1}!");',
    'static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, come back!");': 'static const u8 sText_PkmnComeBack[] = _("¡Vuelve, {B_BUFF1}!");',
    'static const u8 sText_PkmnOkComeBack[] = _("OK, {B_BUFF1}! Come back!");': 'static const u8 sText_PkmnOkComeBack[] = _("¡Bien hecho, {B_BUFF1}! ¡Vuelve!");',
    'static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, that\'s enough! Come back!");': 'static const u8 sText_PkmnThatsEnough[] = _("¡Basta, {B_BUFF1}! ¡Vuelve!");',
    'static const u8 sText_PkmnGoodComeBack[] = _("Good job, {B_BUFF1}! Come back!");': 'static const u8 sText_PkmnGoodComeBack[] = _("¡Buen trabajo, {B_BUFF1}! ¡Vuelve!");',

    # Flee / Win / Draw
    'static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}You got away safely!\\p");': 'static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}¡Escapaste sin problemas!\\p");',
    'static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} used {B_BUFF3}!");': 'static const u8 sText_AttackerUsedX[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó {B_BUFF3}!");',

    # Stat rose / fell
    'const u8 gText_StatSharply[] = _("sharply ");': 'const u8 gText_StatSharply[] = _("mucho ");',
    'const u8 gText_StatRose[] = _("rose!");': 'const u8 gText_StatRose[] = _("subió!");',
    'const u8 gText_StatFell[] = _("fell!");': 'const u8 gText_StatFell[] = _("bajó!");',

    # Table Strings (Core)
    'COMPOUND_STRING("{B_BUFF1} gained{B_BUFF2} {B_BUFF3} Exp. Points!\\p")': 'COMPOUND_STRING("¡{B_BUFF1} ganó{B_BUFF2} {B_BUFF3} puntos de experiencia!\\p")',
    'COMPOUND_STRING("{B_BUFF1} grew to Lv. {B_BUFF2}!{WAIT_SE}\\p")': 'COMPOUND_STRING("¡{B_BUFF1} subió al nivel {B_BUFF2}!{WAIT_SE}\\p")',
    'COMPOUND_STRING("{B_BUFF1} learned {B_BUFF2}!{WAIT_SE}\\p")': 'COMPOUND_STRING("¡{B_BUFF1} aprendió {B_BUFF2}!{WAIT_SE}\\p")',
    'COMPOUND_STRING("{B_BUFF1} wants to learn the move {B_BUFF2}.\\p")': 'COMPOUND_STRING("{B_BUFF1} quiere aprender el movimiento {B_BUFF2}.\\p")',
    'COMPOUND_STRING("However, {B_BUFF1} already knows four moves.\\p")': 'COMPOUND_STRING("Pero {B_BUFF1} ya conoce cuatro movimientos.\\p")',
    'COMPOUND_STRING("Should another move be forgotten and replaced with {B_BUFF2}?")': 'COMPOUND_STRING("¿Quieres olvidar un movimiento para aprender {B_BUFF2}?")',
    'COMPOUND_STRING("{B_BUFF1} forgot {B_BUFF2}…\\p")': 'COMPOUND_STRING("{B_BUFF1} olvidó {B_BUFF2}…\\p")',
    'COMPOUND_STRING("{PAUSE 32}Do you want to give up on having {B_BUFF1} learn {B_BUFF2}?")': 'COMPOUND_STRING("{PAUSE 32}¿Quieres dejar de enseñar {B_BUFF2} a {B_BUFF1}?")',
    'COMPOUND_STRING("{B_BUFF1} did not learn {B_BUFF2}.\\p")': 'COMPOUND_STRING("{B_BUFF1} no aprendió {B_BUFF2}.\\p")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}\'s attack missed!")': 'COMPOUND_STRING("¡El ataque de {B_ATK_NAME_WITH_PREFIX} falló!")',
    'COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} protected itself!")': 'COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se protegió!")',
    'COMPOUND_STRING("It doesn\'t affect {B_DEF_NAME_WITH_PREFIX2}…")': 'COMPOUND_STRING("No afecta a {B_DEF_NAME_WITH_PREFIX2}…")',
    'COMPOUND_STRING("It doesn\'t affect {B_SCR_NAME_WITH_PREFIX2}…")': 'COMPOUND_STRING("No afecta a {B_SCR_NAME_WITH_PREFIX2}…")',
    'COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} fainted!\\p")': 'COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se debilitó!\\p")',
    'COMPOUND_STRING("You got ¥{B_BUFF1} for winning!\\p")': 'COMPOUND_STRING("¡Ganaste ¥{B_BUFF1} por vencer!\\p")',
    'COMPOUND_STRING("You have no more Pokémon that can fight!\\p")': 'COMPOUND_STRING("¡No te quedan más POKéMON para luchar!\\p")',
    'COMPOUND_STRING("You panicked and dropped ¥{B_BUFF1}…")': 'COMPOUND_STRING("Te asustaste y perdiste ¥{B_BUFF1}…")',
    'COMPOUND_STRING("You gave ¥{B_BUFF1} to the winner…")': 'COMPOUND_STRING("Le diste ¥{B_BUFF1} al vencedor…")',
    'COMPOUND_STRING("The Pokémon was hit {B_BUFF1} time(s)!")': 'COMPOUND_STRING("¡Golpeó {B_BUFF1} vez/veces!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell asleep!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se durmió!")',
    'COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is already asleep!")': 'COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está dormido!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was poisoned!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue envenenado!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its poisoning!")': 'COMPOUND_STRING("¡El veneno resta salud a {B_ATK_NAME_WITH_PREFIX}!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was badly poisoned!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue gravemente envenenado!")',
    'COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} had its energy drained!")': 'COMPOUND_STRING("¡Se absorbió energía de {B_DEF_NAME_WITH_PREFIX}!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was burned!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se quemó!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its burn!")': 'COMPOUND_STRING("¡Las quemaduras restan salud a {B_ATK_NAME_WITH_PREFIX}!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was frozen solid!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se congeló!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is frozen solid!")': 'COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está congelado!")',
    'COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} thawed out!")': 'COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se descongeló!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is paralyzed, so it may be unable to move!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está paralizado! ¡Quizá no se mueva!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} couldn\'t move because it\'s paralyzed!")': 'COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está paralizado! ¡No se puede mover!")',
    'COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was cured of paralysis!")': 'COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se curó de la parálisis!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is confused!")': 'COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está confuso!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} snapped out of its confusion!")': 'COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya no está confuso!")',
    'COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became confused!")': 'COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está confuso!")',
    'COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flinched and couldn\'t move!")': 'COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} retrocedió y no pudo moverse!")',
    'COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}\'s HP was restored.")': 'COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} recuperó salud!")',
    'COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}\'s HP is full!")': 'COMPOUND_STRING("¡Los PS de {B_DEF_NAME_WITH_PREFIX} están al máximo!")',
    'COMPOUND_STRING("A critical hit!")': 'COMPOUND_STRING("¡Un golpe crítico!")',
    'COMPOUND_STRING("It\'s super effective!")': 'COMPOUND_STRING("¡Es muy eficaz!")',
    'COMPOUND_STRING("It\'s not very effective…")': 'COMPOUND_STRING("No es muy eficaz…")',
    'COMPOUND_STRING("It\'s a one-hit KO!")': 'COMPOUND_STRING("¡Fulminado de un golpe!")',
}

count = 0
for old, new in replacements.items():
    if old in c:
        c = c.replace(old, new)
        count += 1

with open(path, "w", encoding="utf-8") as f:
    f.write(c)

print(f"[OK] Replaced {count} entries in {path}")
