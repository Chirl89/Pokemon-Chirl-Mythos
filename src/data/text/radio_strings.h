// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("Charla POKéMON de OAK");
static const u8 sRadioStationName_PokedexShow[]     = _("Show de la POKéDEX");
static const u8 sRadioStationName_PokemonMusic[]    = _("Música POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("Canal de la Suerte");
static const u8 sRadioStationName_BuenasPassword[]  = _("La clave de BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("Lugares y Personas");
static const u8 sRadioStationName_LetsAllSing[]     = _("¡Cantemos todos!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLAUTA");

static const u8 sRadioStationName_HoennSound[]  = _("Sonido Hoenn");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("¡Una melodía POKéMON de una");
static const u8 sRadioText_Hoenn2[] = _("lejana región llamada HOENN!");
static const u8 sRadioText_Hoenn3[] = _("¡Los POKéMON salvajes de allí");
static const u8 sRadioText_Hoenn4[] = _("podrían aparecer cerca!");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("¡SHOW DE LA POKéDEX DE OAK!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: El POKéMON de hoy es ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY: ¡CHARLA POKéMON DE OAK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("¡Conmigo, MARY!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("puede verse por");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ¡");
static const u8 sRadioText_OPT_MaryIs[] = _(" es ");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("Canal POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("muy dulcemente");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("muy escurridizo y");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("bien llamado y");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("sin duda alguna");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("tan irresistible y");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("¡vaya, muy");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("casi venenoso y");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("oh, tan");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("tan pícaramente");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("muy de moda y");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("realmente");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("en el agua es");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("al evolucionar es");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocativamente");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("tan alocado y");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("para derretirse,");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("mono.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("raro.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("agradable.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("algo audaz.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("aterrador.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("¡elegante!");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("poderoso.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("emocionante.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("¡genial!");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspirador.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("amistoso.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("¡ardiente!");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("estimulante.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("cauteloso.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("encantador.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("veloz.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN: ¡CANAL MÚSICA POKéMON!");
static const u8 sRadioText_BenIntro2[] = _("¡Aquí vuestro DJ BEN!");
static const u8 sRadioText_FernIntro[] = _("FERN: ¡POKéMÚSICA!");
static const u8 sRadioText_FernIntro2[] = _("¡Con DJ FERN!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Hoy es ");
static const u8 sRadioText_BenFern_JamTo[] = _("así que disfrutad de");
static const u8 sRadioText_BenFern_ChillTo[] = _("así que relajaos con");
static const u8 sRadioText_BenFern_March[] = _("¡La Marcha POKéMON!");
static const u8 sRadioText_BenFern_Lullaby[] = _("¡La Nana POKéMON!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("REED: ¡Yuuuju! ¿Cómo estáis?");
static const u8 sRadioText_LC2[] = _("¡Tanto si subís como si");
static const u8 sRadioText_LC3[] = _("bajáis, no os perdáis el");
static const u8 sRadioText_LC4[] = _("¡SHOW NÚMERO DE LA SUERTE!");
static const u8 sRadioText_LC5[] = _("El número de esta semana es");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("¡Lo repetiré de nuevo!");
static const u8 sRadioText_LC_Match[] = _("¡Si coincide, corred a");
static const u8 sRadioText_LC_Tower[] = _("la TORRE DE RADIO!");
static const u8 sRadioText_LC_Drag1[] = _("…Repetirme todo el rato");
static const u8 sRadioText_LC_Drag2[] = _("acaba siendo un rollo…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("¡LUGARES Y PERSONAS! Con");
static const u8 sRadioText_PnP_Intro2[] = _("vosotros, ¡DJ LILY!");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("es adorable.");
static const u8 sRadioText_PnP_Lazy[]       = _("es algo vago.");
static const u8 sRadioText_PnP_Happy[]      = _("siempre ríe.");
static const u8 sRadioText_PnP_Noisy[]      = _("es muy ruidoso.");
static const u8 sRadioText_PnP_Precocious[] = _("es muy precoz.");
static const u8 sRadioText_PnP_Bold[]       = _("es algo audaz.");
static const u8 sRadioText_PnP_Picky[]      = _("¡es muy tiquismiquis!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("no está nada mal.");
static const u8 sRadioText_PnP_SoSo[]       = _("es pasable.");
static const u8 sRadioText_PnP_Great[]       = _("es genial.");
static const u8 sRadioText_PnP_MyType[]      = _("es justo mi tipo.");
static const u8 sRadioText_PnP_Cool[]        = _("mola un montón.");
static const u8 sRadioText_PnP_Inspiring[]   = _("¡es inspirador!");
static const u8 sRadioText_PnP_Weird[]       = _("es algo raro.");
static const u8 sRadioText_PnP_RightForMe[]  = _("¿será para mí?");
static const u8 sRadioText_PnP_Odd[]         = _("¡es muy extraño!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("…Ejem… ¡Somos el");
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("¡Tras tres años");
static const u8 sRadioText_Rocket4[]  = _("de preparación, hemos");
static const u8 sRadioText_Rocket5[]  = _("resurgido de nuevo");
static const u8 sRadioText_Rocket6[]  = _("de las cenizas!");
static const u8 sRadioText_Rocket7[]  = _("¡GIOVANNI!");
static const u8 sRadioText_Rocket8[]  = _("¿Puedes oírnos?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: ¡Aquí BUENA!");
static const u8 sRadioText_Buena2[] = _("¡La clave de hoy!");
static const u8 sRadioText_Buena3[] = _("Dejadme pensar… Es");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("¡No la olvidéis! Estoy en la");
static const u8 sRadioText_Buena6[] = _("TORRE RADIO de TRIGAL.");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("PUEBLO PRIMAVERA");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CIUDAD CEREZO");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("PUEBLO AZALEA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOLADOR");
static const u8 sRadioBuenaPassword_Bug[]             = _("BICHO");
static const u8 sRadioBuenaPassword_Grass[]           = _("PLANTA");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("Charla POKéMON");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("Música POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Canal de la Suerte");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("MARY: ¡Esta noche, un momento");
static const u8 sOPT_Report_Clefairy_1[]  = _("mágico en la CHARLA POKéMON!");
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: ¡Hablamos del");
static const u8 sOPT_Report_Clefairy_3[]  = _("místico CLEFAIRY!");
static const u8 sOPT_Report_Clefairy_4[]  = _("Se reúnen en MT. MOON");
static const u8 sOPT_Report_Clefairy_5[]  = _("en las noches de luna llena.");
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY: ¡Bailan en círculos!");
static const u8 sOPT_Report_Clefairy_7[]  = _("¡Es tan tierno y curioso!");
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: ¡Un misterio eterno");
static const u8 sOPT_Report_Clefairy_9[]  = _("digno de contemplar!");

static const u8 sOPT_Report_Lapras_0[]  = _("MARY: ¡Un gigante bondadoso");
static const u8 sOPT_Report_Lapras_1[]  = _("llega al show de hoy!");
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: ¡Es el ferri marino,");
static const u8 sOPT_Report_Lapras_3[]  = _("nuestro querido LAPRAS!");
static const u8 sOPT_Report_Lapras_4[]  = _("Visto en CUEVA UNIÓN, pero");
static const u8 sOPT_Report_Lapras_5[]  = _("en ningún otro sitio. ¡Curioso!");
static const u8 sOPT_Report_Lapras_6[]  = _("MARY: ¡Tan raro y pacífico!");
static const u8 sOPT_Report_Lapras_7[]  = _("¡Y además canta!");
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Dicen que su canto calma");
static const u8 sOPT_Report_Lapras_9[]  = _("el alma de los mares.");

static const u8 sOPT_Report_Ampharos_0[]  = _("MARY: ¡Bienvenidos de nuevo!");
static const u8 sOPT_Report_Ampharos_1[]  = _("¡Hora de la CHARLA POKéMON!");
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: ¡Demos luz a");
static const u8 sOPT_Report_Ampharos_3[]  = _("nuestro amigo AMPHAROS!");
static const u8 sOPT_Report_Ampharos_4[]  = _("Su cola brilla en la niebla");
static const u8 sOPT_Report_Ampharos_5[]  = _("guiando a los marineros.");
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY: ¡Poderoso, elegante");
static const u8 sOPT_Report_Ampharos_7[]  = _("y muy cariñoso!");
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: ¡Protagonista de muchas");
static const u8 sOPT_Report_Ampharos_9[]  = _("historias de faros!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY: Ahora, un caso insólito");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("en la RUTA 36…");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: ¡SUDOWOODO! Parece un");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("árbol, ¡pero no lo es!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Bloquea el camino y no se");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("mueve sin agua.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY: ¡Solo reacciona a la");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("REGADERA!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: ¡No es una planta, es un");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("tipo ROCA camuflado!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY: ¡Hoy traemos noticias");
static const u8 sOPT_Report_RedGyarados_1[]  = _("impactantes desde JOHTO!");
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: ¡Vieron un GYARADOS ROJO");
static const u8 sOPT_Report_RedGyarados_3[]  = _("en el LAGO DE LA FURIA!");
static const u8 sOPT_Report_RedGyarados_4[]  = _("A diferencia de los azules,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("¡este es carmesí brillante!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY: ¡Dicen que se debe a");
static const u8 sOPT_Report_RedGyarados_7[]  = _("unas extrañas ondas de radio!");
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: Una evolución misteriosa…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Posiblemente forzada.");

static const u8 sOPT_Report_Unown_0[]  = _("MARY: ¿Habéis visitado las");
static const u8 sOPT_Report_Unown_1[]  = _("RUINAS ALFA? ¡Qué misterio!");
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Hay extraños símbolos");
static const u8 sOPT_Report_Unown_3[]  = _("en las paredes antiguas.");
static const u8 sOPT_Report_Unown_4[]  = _("Dentro habitan los UNOWN…");
static const u8 sOPT_Report_Unown_5[]  = _("¡con formas de letras!");
static const u8 sOPT_Report_Unown_6[]  = _("MARY: ¿Formarán palabras?");
static const u8 sOPT_Report_Unown_7[]  = _("¡O solo quieren asustar!");
static const u8 sOPT_Report_Unown_8[]  = _("OAK: Un gran enigma natural,");
static const u8 sOPT_Report_Unown_9[]  = _("aún sin resolver hoy en día.");

static const u8 sOPT_Report_Snubbull_0[]  = _("MARY: ¡En CIUDAD TRIGAL");
static const u8 sOPT_Report_Snubbull_1[]  = _("buscan sin parar!");
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: ¡Un SNUBBULL travieso");
static const u8 sOPT_Report_Snubbull_3[]  = _("se ha escapado!");
static const u8 sOPT_Report_Snubbull_4[]  = _("Suele ser tímido, pero lo");
static const u8 sOPT_Report_Snubbull_5[]  = _("vieron cerca de la estación.");
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY: ¡Quizás busca aventuras");
static const u8 sOPT_Report_Snubbull_7[]  = _("o nuevos amigos!");
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: ¡Abrid bien los ojos");
static const u8 sOPT_Report_Snubbull_9[]  = _("y tened la correa lista!");

static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY: ¡Grandes noticias desde");
static const u8 sOPT_Report_Slowpoke_1[]  = _("PUEBLO AZALEA esta semana!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: ¡Los SLOWPOKE han vuelto");
static const u8 sOPT_Report_Slowpoke_3[]  = _("a su pozo tras el peligro!");
static const u8 sOPT_Report_Slowpoke_4[]  = _("¡El TEAM ROCKET les cortaba");
static const u8 sOPT_Report_Slowpoke_5[]  = _("las colas! ¡Qué barbaridad!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY: ¡Pero un valiente");
static const u8 sOPT_Report_Slowpoke_7[]  = _("entrenador los detuvo!");
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: Los SLOWPOKE están a salvo");
static const u8 sOPT_Report_Slowpoke_9[]  = _("y sestean felices de nuevo.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY: ¡La torre de PUEBLO");
static const u8 sOPT_Report_LavenderTower_1[]  = _("LAVANDA ha cambiado de aires!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: ¡La vieja torre fantasmal");
static const u8 sOPT_Report_LavenderTower_3[]  = _("es ahora la TORRE DE RADIO!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Algunos dicen que aún da");
static const u8 sOPT_Report_LavenderTower_5[]  = _("bastante repelús…");
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY: ¡Juraría que vi un GASTLY");
static const u8 sOPT_Report_LavenderTower_7[]  = _("junto al micrófono!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Quizás fuera estática…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("¡o espectros!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY: ¡Noticias curiosas desde");
static const u8 sOPT_Report_Tentacruel_1[]  = _("las ISLAS REMOLINO!");
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: ¡Varios TENTACRUEL rodean");
static const u8 sOPT_Report_Tentacruel_3[]  = _("la entrada a las cuevas!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Son enormes y actúan con");
static const u8 sOPT_Report_Tentacruel_5[]  = _("mucho celo territorial.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY: Bloquean el paso pero");
static const u8 sOPT_Report_Tentacruel_7[]  = _("sin atacar…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: Como si vigilaran algo");
static const u8 sOPT_Report_Tentacruel_9[]  = _("en lo más hondo del mar.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
