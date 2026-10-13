const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("HEDOR"),
        .description = COMPOUND_STRING("Debido al mal olor que emana, al atacar al rival puede hacerlo retroceder."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("LLOVIZNA"),
        .description = COMPOUND_STRING("Hace que llueva cuando entra en combate."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("IMPULSO"),
        .description = COMPOUND_STRING("Aumenta la Velocidad en cada turno."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("ARMADURA BATALLA"),
        .description = COMPOUND_STRING("La robusta coraza que lo protege bloquea los golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("ROBUSTEZ"),
        .description = COMPOUND_STRING("Evita que el rival pueda debilitarlo de un solo golpe cuando tiene los PS al máximo. También anula los movimientos fulminantes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("HUMEDAD"),
        .description = COMPOUND_STRING("Aumenta la humedad del entorno y evita que se puedan utilizar movimientos explosivos, tales como Autodestrucción."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("FLEXIBILIDAD"),
        .description = COMPOUND_STRING("Evita ser paralizado gracias a la flexibilidad de su cuerpo."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("VELO ARENA"),
        .description = COMPOUND_STRING("Aumenta la Evasión durante las tormentas de arena."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("ELEC. ESTÁTICA"),
        .description = COMPOUND_STRING("La electricidad estática que lo envuelve puede paralizar al mínimo contacto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("ABSORBE ELEC"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Eléctrico, recupera PS en vez de sufrir daño."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("ABSORBE AGUA"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Agua, recupera PS en vez de sufrir daño."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("DESPISTE"),
        .description = COMPOUND_STRING("La indiferencia del Pokémon evita que caiga presa del enamoramiento o sea provocado."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("ACLIMATACIÓN"),
        .description = COMPOUND_STRING("Anula todos los efectos del tiempo atmosférico."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("OJO COMPUESTO"),
        .description = COMPOUND_STRING("Aumenta la precisión de sus movimientos."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("INSOMNIO"),
        .description = COMPOUND_STRING("Su resistencia al sueño le impide quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("CAMBIO COLOR"),
        .description = COMPOUND_STRING("Adopta el tipo del último movimiento del que se es blanco."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("INMUNIDAD"),
        .description = COMPOUND_STRING("Su sistema inmunitario evita el envenenamiento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("ABSORBE FUEGO"),
        .description = COMPOUND_STRING("Si le alcanza algún movimiento de tipo Fuego, potencia sus propios movimientos de dicho tipo."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("POLVO ESCUDO"),
        .description = COMPOUND_STRING("El polvo de escamas que lo envuelve lo protege de los efectos secundarios de los ataques recibidos."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("RITMO PROPIO"),
        .description = COMPOUND_STRING("Como le gusta hacer las cosas a su manera, los rivales no logran confundirlo."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("VENTOSAS"),
        .description = COMPOUND_STRING("Sus ventosas se aferran al suelo, con lo cual anula movimientos y objetos que fuerzan el relevo."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("INTIMIDACIÓN"),
        .description = COMPOUND_STRING("Al entrar en combate amilana al rival de tal manera que su Ataque disminuye."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("SOMBRA TRAMPA"),
        .description = COMPOUND_STRING("Evita que el enemigo huya o sea cambiado por otro."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("PIEL TOSCA"),
        .description = COMPOUND_STRING("Hiere con su piel áspera al rival que lo ataque con un movimiento de contacto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("SUPERGUARDA"),
        .description = COMPOUND_STRING("Gracias a un poder misterioso, solo le hacen daño los movimientos supereficaces."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("LEVITACIÓN"),
        .description = COMPOUND_STRING("Su capacidad de flotar sobre el suelo le proporciona inmunidad frente a los movimientos de tipo Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("EFECTO ESPORA"),
        .description = COMPOUND_STRING("Puede dormir, envenenar o paralizar al Pokémon con el que entre en contacto al recibir un ataque."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("SINCRONÍA"),
        .description = COMPOUND_STRING("Contagia el envenenamiento, las quemaduras o la parálisis al Pokémon que le cause ese estado."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("CUERPO PURO"),
        .description = COMPOUND_STRING("Evita que bajen sus características a causa de movimientos o habilidades de otros Pokémon."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("CURA NATURAL"),
        .description = COMPOUND_STRING("Cura problemas de estado al cambiar de Pokémon."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("PARARRAYOS"),
        .description = COMPOUND_STRING("Además de atraer y neutralizar los movimientos de tipo Eléctrico, sube el Ataque Especial."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("DICHA"),
        .description = COMPOUND_STRING("Aumenta la probabilidad de que los movimientos causen efectos secundarios."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("NADO RÁPIDO"),
        .description = COMPOUND_STRING("Sube la Velocidad cuando llueve."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("CLOROFILA"),
        .description = COMPOUND_STRING("Sube la Velocidad cuando hace sol."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("ILUMINACIÓN"),
        .description = COMPOUND_STRING("Aumenta la probabilidad de encontrar Pokémon al aumentar la visibilidad del entorno."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("RASTRO"),
        .description = COMPOUND_STRING("Al entrar en combate copia la habilidad del rival."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("POTENCIA"),
        .description = COMPOUND_STRING("Duplica la potencia de los ataques físicos."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("PUNTO TÓXICO"),
        .description = COMPOUND_STRING("Puede envenenar al mínimo contacto."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("FOCO INTERNO"),
        .description = COMPOUND_STRING("Gracias a su profunda concentración, no retrocede ante los ataques del rival."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("ESCUDO MAGMA"),
        .description = COMPOUND_STRING("Gracias al magma candente que lo envuelve, evita la congelación."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("VELO AGUA"),
        .description = COMPOUND_STRING("Evita las quemaduras gracias a la capa de agua que lo envuelve."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("IMÁN"),
        .description = COMPOUND_STRING("Su magnetismo atrae a los Pokémon de tipo Acero y les impide huir."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("INSONORIZAR"),
        .description = COMPOUND_STRING("Su aislamiento acústico lo protege de movimientos que usan sonido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("CURA LLUVIA"),
        .description = COMPOUND_STRING("Recupera PS de forma gradual cuando llueve."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("CHORRO ARENA"),
        .description = COMPOUND_STRING("Crea una tormenta de arena al entrar en combate."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("PRESIÓN"),
        .description = COMPOUND_STRING("Presiona al rival para que sus PP se acaben antes."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("SEBO"),
        .description = COMPOUND_STRING("Gracias a la gruesa capa de grasa que lo protege, reduce a la mitad el daño recibido por ataques de tipo Fuego y Hielo."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("MADRUGAR"),
        .description = COMPOUND_STRING("Si el Pokémon se duerme, tardará la mitad de tiempo en despertarse."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("CUERPO LLAMA"),
        .description = COMPOUND_STRING("Puede quemar al mínimo contacto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("FUGA"),
        .description = COMPOUND_STRING("Permite escapar de todos los Pokémon salvajes."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("VISTA LINCE"),
        .description = COMPOUND_STRING("La aguda vista de este Pokémon evita que disminuya su Precisión."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("CORTE FUERTE"),
        .description = COMPOUND_STRING("Evita que el rival le baje el Ataque."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("RECOGIDA"),
        .description = COMPOUND_STRING("El Pokémon puede recoger objetos que el rival haya usado, o bien otros que encuentre en plena aventura."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("AUSENTE"),
        .description = COMPOUND_STRING("Al ejecutar un movimiento, el Pokémon descansará en el turno siguiente."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("ENTUSIASMO"),
        .description = COMPOUND_STRING("Aumenta el Ataque, pero reduce la Precisión."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("GRAN ENCANTO"),
        .description = COMPOUND_STRING("Entrar en contacto con el Pokémon puede causar enamoramiento."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("MÁS"),
        .description = COMPOUND_STRING("Potencia el Ataque Especial si un Pokémon aliado tiene la habilidad Más o Menos."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("MENOS"),
        .description = COMPOUND_STRING("Potencia el Ataque Especial si un Pokémon aliado tiene la habilidad Más o Menos."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("PREDICCIÓN"),
        .description = COMPOUND_STRING("Cambia a tipo Agua, Fuego o Hielo en función del tiempo atmosférico."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("VISCOSIDAD"),
        .description = COMPOUND_STRING("Protege al Pokémon del robo de objetos al quedarse pegados a su cuerpo."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("MUDAR"),
        .description = COMPOUND_STRING("El Pokémon puede curar sus problemas de estado al mudar la piel."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("AGALLAS"),
        .description = COMPOUND_STRING("Si sufre un problema de estado, se viene arriba y aumenta su Ataque."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("ESCAMA ESPECIAL"),
        .description = COMPOUND_STRING("Sube la Defensa si el Pokémon sufre un problema de estado."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("LODO LÍQUIDO"),
        .description = COMPOUND_STRING("Debido a su intenso hedor, hiere a los Pokémon que intentan drenarle los PS."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("ESPESURA"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Planta del Pokémon cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("MAR LLAMAS"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Fuego del Pokémon cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("TORRENTE"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Agua del Pokémon cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("ENJAMBRE"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Bicho del Pokémon cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("CABEZA ROCA"),
        .description = COMPOUND_STRING("Impide que el Pokémon se dañe con sus propios movimientos."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("SEQUÍA"),
        .description = COMPOUND_STRING("Cuando el Pokémon entra en combate, el tiempo pasa a ser soleado."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("TRAMPA ARENA"),
        .description = COMPOUND_STRING("Evita que el rival huya."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("ESPÍRITU VITAL"),
        .description = COMPOUND_STRING("Su determinación le impide quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("HUMO BLANCO"),
        .description = COMPOUND_STRING("El humo blanco que lo protege evita que otro Pokémon le baje las características."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("ENERGÍA PURA"),
        .description = COMPOUND_STRING("Duplica la potencia de los ataques físicos."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("CAPARAZÓN"),
        .description = COMPOUND_STRING("La robusta coraza que lo protege bloquea los golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("BUCLE AIRE"),
        .description = COMPOUND_STRING("Neutraliza todos los efectos del tiempo atmosférico."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("TUMBOS"),
        .description = COMPOUND_STRING("Sube la Evasión si el Pokémon está confuso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("ELECTROMOTOR"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Eléctrico, le sube la Velocidad en vez de sufrir daño."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("RIVALIDAD"),
        .description = COMPOUND_STRING("Si el objetivo es del mismo sexo, su competitividad le lleva a infligir más daño. Si es del sexo contrario, en cambio, el daño será menor."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("IMPASIBLE"),
        .description = COMPOUND_STRING("Cada vez que retrocede sube su Velocidad, debido a su voluntad inquebrantable."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("MANTO NÍVEO"),
        .description = COMPOUND_STRING("Sube la Evasión cuando graniza."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("GULA"),
        .description = COMPOUND_STRING("Cuando sus PS se ven reducidos a la mitad, engulle la baya que normalmente solo se comería cuando le quedasen pocos PS."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("IRASCIBLE"),
        .description = COMPOUND_STRING("Si recibe un golpe crítico, monta en cólera y sube su Ataque hasta el máximo."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("LIVIANO"),
        .description = COMPOUND_STRING("Sube la Velocidad si usa o pierde el objeto que lleva."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("IGNÍFUGO"),
        .description = COMPOUND_STRING("Su cuerpo, resistente al calor, reduce a la mitad el daño recibido por movimientos de tipo Fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("SIMPLE"),
        .description = COMPOUND_STRING("Duplica los cambios en las características."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("PIEL SECA"),
        .description = COMPOUND_STRING("Pierde PS si hace sol y los recupera si llueve o recibe un movimiento de tipo Agua. Los movimientos de tipo Fuego, por su parte, le hacen más daño de lo normal."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("DESCARGA"),
        .description = COMPOUND_STRING("Compara la Defensa y la Defensa Especial del rival para ver cuál es inferior y aumenta su propio Ataque o Ataque Especial, según corresponda."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("PUÑO FÉRREO"),
        .description = COMPOUND_STRING("Aumenta la potencia de los puñetazos."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("ANTÍDOTO"),
        .description = COMPOUND_STRING("Si el Pokémon resulta envenenado, recupera PS en vez de perderlos."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("ADAPTABLE"),
        .description = COMPOUND_STRING("Potencia aún más los movimientos cuyo tipo coincida con el del Pokémon."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("ENCADENADO"),
        .description = COMPOUND_STRING("Los movimientos múltiples se ejecutarán siempre con el número máximo de golpes."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("HIDRATACIÓN"),
        .description = COMPOUND_STRING("Cura los problemas de estado si está lloviendo."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("PODER SOLAR"),
        .description = COMPOUND_STRING("Si hace sol, aumenta su Ataque Especial, pero pierde PS en cada turno."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("PIES RÁPIDOS"),
        .description = COMPOUND_STRING("Aumenta la Velocidad si sufre problemas de estado."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("NORMALIDAD"),
        .description = COMPOUND_STRING("Todos los movimientos se vuelven de tipo Normal y aumentan ligeramente su potencia."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("FRANCOTIRADOR"),
        .description = COMPOUND_STRING("Potencia los golpes críticos aún más de lo normal."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("MURO MÁGICO"),
        .description = COMPOUND_STRING("El Pokémon solo recibe daño de ataques."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("INDEFENSO"),
        .description = COMPOUND_STRING("Al quedar ambos expuestos, tanto los movimientos del Pokémon como los del rival acertarán siempre."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("REZAGADO"),
        .description = COMPOUND_STRING("El Pokémon ejecuta su movimiento tras todos los demás."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("EXPERTO"),
        .description = COMPOUND_STRING("Potencia los movimientos más débiles del Pokémon."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("DEFENSA HOJA"),
        .description = COMPOUND_STRING("Evita los problemas de estado si hace sol."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("ZOQUETE"),
        .description = COMPOUND_STRING("El Pokémon no puede usar objetos equipados."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("ROMPEMOLDES"),
        .description = COMPOUND_STRING("Las habilidades del objetivo no afectan a los movimientos empleados."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("AFORTUNADO"),
        .description = COMPOUND_STRING("Su buena suerte aumenta la probabilidad de asestar golpes críticos."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("DETONACIÓN"),
        .description = COMPOUND_STRING("Daña al agresor que le ha dado el golpe de gracia con un movimiento de contacto."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("ANTICIPACIÓN"),
        .description = COMPOUND_STRING("Prevé los movimientos peligrosos del rival."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("ALERTA"),
        .description = COMPOUND_STRING("Determina el movimiento más potente del rival al entrar en combate."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("IGNORANTE"),
        .description = COMPOUND_STRING("Pasa por alto las mejoras en las características del rival al atacar."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("CROMOLENTE"),
        .description = COMPOUND_STRING("Potencia los movimientos que no son muy eficaces."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("FILTRO"),
        .description = COMPOUND_STRING("Mitiga el daño que le infligen los movimientos supereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("INICIO LENTO"),
        .description = COMPOUND_STRING("Baja a la mitad el Ataque y la Velocidad durante cinco turnos."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("INTRÉPIDO"),
        .description = COMPOUND_STRING("Los movimientos de tipo Normal o Lucha alcanzan a los Pokémon de tipo Fantasma."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("COLECTOR"),
        .description = COMPOUND_STRING("Además de atraer y neutralizar los movimientos de tipo Agua, sube el Ataque Especial."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("GÉLIDO"),
        .description = COMPOUND_STRING("Recupera PS de forma gradual cuando hay tormentas de granizo."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("ROCA SÓLIDA"),
        .description = COMPOUND_STRING("Mitiga el daño que le infligen los movimientos supereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("NEVADA"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("El Pokémon invoca una tormenta de granizo al entrar en combate."),
    #else
        .description = COMPOUND_STRING("El Pokémon invoca una tormenta de granizo al entrar en combate."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("RECOGEMIEL"),
        .description = COMPOUND_STRING("Es posible que el Pokémon encuentre Miel una vez concluido el combate."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("CACHEO"),
        .description = COMPOUND_STRING("El Pokémon puede ver el objeto que lleva el rival al entrar en combate."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("AUDAZ"),
        .description = COMPOUND_STRING("Potencia los movimientos que también dañan al usuario."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("MULTITIPO"),
        .description = COMPOUND_STRING("Cambia el tipo del Pokémon al de la tabla o al del Cristal Z que lleve."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("DON FLORAL"),
        .description = COMPOUND_STRING("Aumenta el Ataque y la Defensa Especial de todos los Pokémon del equipo si hace sol."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("MAL SUEÑO"),
        .description = COMPOUND_STRING("Inflige daño a cualquier rival que esté dormido."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("HURTO"),
        .description = COMPOUND_STRING("Si el rival usa un movimiento de contacto al atacar, le roba el objeto."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("POTENCIA BRUTA"),
        .description = COMPOUND_STRING("Sube la potencia de los movimientos en detrimento de los efectos secundarios, que se ven anulados."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("RESPONDÓN"),
        .description = COMPOUND_STRING("Invierte los cambios en las características: bajan cuando les toca subir y suben cuando les toca bajar."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("NERVIOSISMO"),
        .description = COMPOUND_STRING("Pone nervioso al rival y le impide usar bayas."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("COMPETITIVO"),
        .description = COMPOUND_STRING("Sube mucho el Ataque cuando el rival le baja las características."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("FLAQUEZA"),
        .description = COMPOUND_STRING("Se debilita tanto cuando sus PS se ven reducidos a la mitad que su Ataque y su Ataque Especial bajan."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("CUERPO MALDITO"),
        .description = COMPOUND_STRING("Puede anular el movimiento usado en su contra."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("ALMA CURA"),
        .description = COMPOUND_STRING("A veces cura los problemas de estado de un aliado."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("COMPIESCOLTA"),
        .description = COMPOUND_STRING("Reduce el daño que sufren los aliados."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("ARMADURA FRÁGIL"),
        .description = COMPOUND_STRING("Al recibir daño por un ataque físico, baja la Defensa, pero sube mucho la Velocidad del Pokémon."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("METAL PESADO"),
        .description = COMPOUND_STRING("Duplica el peso del Pokémon."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("METAL LIVIANO"),
        .description = COMPOUND_STRING("Reduce a la mitad el peso del Pokémon."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("MULTIESCAMAS"),
        .description = COMPOUND_STRING("Reduce el daño sufrido si los PS están al máximo."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("ÍMPETU TÓXICO"),
        .description = COMPOUND_STRING("Aumenta la potencia de los ataques físicos cuando el Pokémon está envenenado."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("ÍMPETU ARDIENTE"),
        .description = COMPOUND_STRING("Aumenta la potencia de los ataques especiales cuando el Pokémon sufre quemaduras."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("COSECHA"),
        .description = COMPOUND_STRING("Permite reutilizar varias veces una misma baya."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("TELEPATÍA"),
        .description = COMPOUND_STRING("Elude los ataques de los aliados durante el combate."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("VELETA"),
        .description = COMPOUND_STRING("Cada turno sube mucho una característica, pero baja otra."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("FUNDA"),
        .description = COMPOUND_STRING("Protege al Pokémon de las tormentas de arena, el granizo y los movimientos con polvos."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("TOQUE TÓXICO"),
        .description = COMPOUND_STRING("Puede envenenar al objetivo con solo tocarlo."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("REGENERACIÓN"),
        .description = COMPOUND_STRING("Recupera unos pocos PS al cambiar de Pokémon."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("SACAPECHO"),
        .description = COMPOUND_STRING("Impide que el rival baje la Defensa del Pokémon."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("ÍMPETU ARENA"),
        .description = COMPOUND_STRING("Aumenta la Velocidad durante las tormentas de arena."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("PIEL MILAGRO"),
        .description = COMPOUND_STRING("Ofrece una mayor resistencia ante los ataques de estado."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("CÁLCULO FINAL"),
        .description = COMPOUND_STRING("Aumenta la potencia del movimiento si es el último en atacar."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("ILUSIÓN"),
        .description = COMPOUND_STRING("Adopta el aspecto del último Pokémon del equipo al entrar en combate para desconcertar al rival."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("IMPOSTOR"),
        .description = COMPOUND_STRING("El Pokémon se transforma en el que tiene enfrente."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("ALLANAMIENTO"),
        .description = COMPOUND_STRING("Ataca rodeando la barrera o el sustituto del rival."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("MOMIA"),
        .description = COMPOUND_STRING("Contagia la habilidad Momia al rival que entre en contacto con él."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("AUTOESTIMA"),
        .description = COMPOUND_STRING("Al debilitar a un objetivo, su confianza se refuerza de tal manera que aumenta el Ataque."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("JUSTICIERO"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Siniestro, aumenta el Ataque debido a su integridad."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("COBARDÍA"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Siniestro, Bicho o Fantasma, el miedo hace que le suba la Velocidad."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("ESPEJO MÁGICO"),
        .description = COMPOUND_STRING("Permite devolver los ataques de estado lanzados por el rival, sin verse afectado por ellos."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("HERBÍVORO"),
        .description = COMPOUND_STRING("Neutraliza los movimientos de tipo Planta y sube el Ataque."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("BROMISTA"),
        .description = COMPOUND_STRING("Permite lanzar ataques de estado en primer lugar."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("PODER ARENA"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Tierra, Acero y Roca durante las tormentas de arena."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("PUNTA ACERO"),
        .description = COMPOUND_STRING("Inflige daño al rival si este golpea al Pokémon con un movimiento de contacto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("MODO DARUMA"),
        .description = COMPOUND_STRING("Cambia de forma si sus PS se ven reducidos a la mitad."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("TINOVICTORIA"),
        .description = COMPOUND_STRING("Sube la Precisión de todo el equipo."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("TURBOLLAMA"),
        .description = COMPOUND_STRING("Las habilidades del objetivo no afectan a los movimientos empleados."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("TERRAVOLTAJE"),
        .description = COMPOUND_STRING("Las habilidades del objetivo no afectan a los movimientos empleados."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("VELO AROMA"),
        .description = COMPOUND_STRING("Protege a todo el equipo de ataques que impiden elegir movimientos."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("VELO FLOR"),
        .description = COMPOUND_STRING("Evita que los Pokémon de tipo Planta aliados sufran problemas de estado o que bajen sus características."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("CARRILLO"),
        .description = COMPOUND_STRING("Recupera PS al comer cualquier baya."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("MUTATIPO"),
        .description = COMPOUND_STRING("Cambia su tipo al del movimiento que va a usar."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("PELAJE RECIO"),
        .description = COMPOUND_STRING("Reduce a la mitad el daño recibido por ataques físicos del rival."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("PRESTIDIGITADOR"),
        .description = COMPOUND_STRING("Roba el objeto del Pokémon al que alcance con un movimiento."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("ANTIBALAS"),
        .description = COMPOUND_STRING("No le afectan las bombas ni algunos proyectiles."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("TENACIDAD"),
        .description = COMPOUND_STRING("Aumenta mucho su Ataque Especial cuando el rival le baja cualquiera de sus características."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("MANDÍBULA FUERTE"),
        .description = COMPOUND_STRING("Su robusta mandíbula le confiere una mordedura potente."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("PIEL HELADA"),
        .description = COMPOUND_STRING("Convierte los movimientos de tipo Normal en tipo Hielo y aumenta ligeramente su potencia."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("VELO DULCE"),
        .description = COMPOUND_STRING("Evita que el equipo Pokémon se duerma."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("CAMBIO TÁCTICO"),
        .description = COMPOUND_STRING("Adopta la Forma Filo al lanzar un ataque, o bien la Forma Escudo si usa el movimiento Escudo Real."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("ALAS VENDAVAL"),
        .description = COMPOUND_STRING("Da prioridad a los movimientos de tipo Volador si los PS están al máximo."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("MEGADISPARADOR"),
        .description = COMPOUND_STRING("Aumenta la potencia de algunos movimientos de pulsos y auras."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("MANTO FRONDOSO"),
        .description = COMPOUND_STRING("Aumenta la Defensa si hay un campo de hierba en el terreno de combate."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("SIMBIOSIS"),
        .description = COMPOUND_STRING("El Pokémon pasa su objeto a un aliado que ya haya utilizado el suyo."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("GARRA DURA"),
        .description = COMPOUND_STRING("Aumenta la potencia de los movimientos de contacto."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("PIEL FEÉRICA"),
        .description = COMPOUND_STRING("Convierte los movimientos de tipo Normal en tipo Hada y aumenta ligeramente su potencia."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("BABA"),
        .description = COMPOUND_STRING("Baja la Velocidad del rival cuando este ataca al Pokémon con un movimiento de contacto."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("PIEL CELESTE"),
        .description = COMPOUND_STRING("Convierte los movimientos de tipo Normal en tipo Volador y aumenta ligeramente su potencia."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("AMOR FILIAL"),
        .description = COMPOUND_STRING("Ataque doble en familia."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("AURA OSCURA"),
        .description = COMPOUND_STRING("Aumenta la potencia de todos los movimientos de tipo Siniestro."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("AURA FEÉRICA"),
        .description = COMPOUND_STRING("Aumenta la potencia de todos los movimientos de tipo Hada."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("ROMPEAURA"),
        .description = COMPOUND_STRING("Invierte los efectos de las auras, por lo que baja la potencia de ciertos movimientos en vez de subirla."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("MAR DEL ALBOR"),
        .description = COMPOUND_STRING("Altera el clima para anular los ataques de tipo Fuego."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("TIERRA DEL OCASO"),
        .description = COMPOUND_STRING("Altera el clima para anular los ataques de tipo Agua."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("RÁFAGA DELTA"),
        .description = COMPOUND_STRING("Altera el clima para anular las vulnerabilidades del tipo Volador."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("FIRMEZA"),
        .description = COMPOUND_STRING("Aumenta la Defensa al recibir un ataque."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("HUIDA"),
        .description = COMPOUND_STRING("Se asusta y abandona el terreno de combate cuando sus PS se ven reducidos a la mitad."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("RETIRADA"),
        .description = COMPOUND_STRING("Abandona el terreno de combate cuando sus PS se ven reducidos a la mitad para evitar males mayores."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("HIDRORREFUERZO"),
        .description = COMPOUND_STRING("Aumenta mucho la Defensa si le alcanza un movimiento de tipo Agua."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("ENSAÑAMIENTO"),
        .description = COMPOUND_STRING("Hace que los movimientos asesten siempre un golpe crítico si el rival está envenenado."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("ESCUDO LIMITADO"),
        .description = COMPOUND_STRING("Rompe su coraza cuando sus PS se ven reducidos a la mitad y adopta una forma ofensiva."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("VIGILANTE"),
        .description = COMPOUND_STRING("Duplica el daño infligido a un Pokémon que se haya incorporado al combate mediante un cambio."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("POMPA"),
        .description = COMPOUND_STRING("Reduce el daño que le provocan los movimientos de tipo Fuego e impide que sufra quemaduras."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("ACERO TEMPLADO"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Acero."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("CÓLERA"),
        .description = COMPOUND_STRING("Aumenta el Ataque Especial si los ataques del oponente le reducen los PS a la mitad."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("QUITANIEVES"),
        .description = COMPOUND_STRING("Aumenta su Velocidad si está granizando."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("REMOTO"),
        .description = COMPOUND_STRING("Permite usar cualquier movimiento sin entrar en contacto con el rival."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("VOZ FLUIDA"),
        .description = COMPOUND_STRING("Hace que todos los movimientos del Pokémon basados en sonido pasen a ser de tipo Agua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("PRIMER AUXILIO"),
        .description = COMPOUND_STRING("Da prioridad a los movimientos que curan PS directamente al Pokémon."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("PIEL ELÉCTRICA"),
        .description = COMPOUND_STRING("Convierte los movimientos de tipo Normal en tipo Eléctrico y aumenta ligeramente su potencia."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("COLA SURF"),
        .description = COMPOUND_STRING("Duplica la Velocidad si hay un campo eléctrico en el terreno de combate."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("BANCO"),
        .description = COMPOUND_STRING("Forma bancos con sus congéneres cuando tiene muchos PS, lo cual le otorga más fuerza. Cuando le quedan pocos PS, el banco se dispersa."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("DISFRAZ"),
        .description = COMPOUND_STRING("Permite eludir un único ataque valiéndose de la tela que le cubre el cuerpo."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("FUERTE AFECTO"),
        .description = COMPOUND_STRING("Al derrotar a un rival, los vínculos con su Entrenador se refuerzan y se convierte en Greninja Ash. Su Shuriken de Agua también se ve potenciado."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("AGRUPAMIENTO"),
        .description = COMPOUND_STRING("Cuando sus PS se ven reducidos a la mitad, las células se reagrupan y adopta su Forma Completa."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("CORROSIÓN"),
        .description = COMPOUND_STRING("Permite envenenar incluso a rivales de tipo Acero o Veneno."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("LETARGO PERENNE"),
        .description = COMPOUND_STRING("No despierta jamás de su profundo letargo  e incluso ataca dormido."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("REGIA PRESENCIA"),
        .description = COMPOUND_STRING("Intimida al rival y le impide usar movimientos con prioridad dirigidos al Pokémon."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("REVÉS"),
        .description = COMPOUND_STRING("Al caer debilitado, inflige al rival un daño equivalente a los PS que le quedaran."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("PAREJA DE BAILE"),
        .description = COMPOUND_STRING("Permite copiar inmediatamente cualquier movimiento de baile que haya usado otro Pokémon presente en el combate."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("BATERÍA"),
        .description = COMPOUND_STRING("Potencia los movimientos especiales de los aliados."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("PELUCHE"),
        .description = COMPOUND_STRING("Reduce a la mitad el daño provocado por los movimientos de contacto, pero duplica el infligido por los de tipo Fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("CUERPO VÍVIDO"),
        .description = COMPOUND_STRING("Desconcierta al rival y le impide utilizar movimientos con prioridad contra el usuario."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("CORÁNIMA"),
        .description = COMPOUND_STRING("Aumenta el Ataque Especial cada vez que un Pokémon cae debilitado."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("RIZOS REBELDES"),
        .description = COMPOUND_STRING("Baja la Velocidad del rival cuando este ataca al Pokémon con un movimiento de contacto."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("RECEPTOR"),
        .description = COMPOUND_STRING("Adquiere la habilidad de un aliado debilitado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("REACCIÓN QUÍMICA"),
        .description = COMPOUND_STRING("Reacciona copiando la habilidad de un aliado debilitado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("ULTRAIMPULSO"),
        .description = COMPOUND_STRING("Si el Pokémon derrota a un rival en ese turno, aumenta su característica más fuerte."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("SISTEMA ALFA"),
        .description = COMPOUND_STRING("Cambia su tipo según el disco que lleve instalado."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("ELECTROGÉNESIS"),
        .description = COMPOUND_STRING("Crea un campo eléctrico al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("PSICOGÉNESIS"),
        .description = COMPOUND_STRING("Crea un campo psíquico al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("NEBULOGÉNESIS"),
        .description = COMPOUND_STRING("Crea un campo de niebla al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("HERBOGÉNESIS"),
        .description = COMPOUND_STRING("Crea un campo de hierba al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("GUARDIA METÁLICA"),
        .description = COMPOUND_STRING("Evita que bajen sus características a causa de movimientos o habilidades de otros Pokémon."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("GUARDIA ESPECTRO"),
        .description = COMPOUND_STRING("Reduce el daño sufrido si los PS están al máximo."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("ARMADURA PRISMA"),
        .description = COMPOUND_STRING("Mitiga el daño que le infligen los movimientos supereficaces."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("FUERZA CEREBRAL"),
        .description = COMPOUND_STRING("Potencia los ataques supereficaces."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("ESPADA INDÓMITA"),
        .description = COMPOUND_STRING("Aumenta su Ataque al entrar en combate."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("ESCUDO RECIO"),
        .description = COMPOUND_STRING("Aumenta su Defensa al entrar en combate."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LÍBERO"),
        .description = COMPOUND_STRING("Cambia su tipo al del movimiento que va a usar."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("RECOGEBOLAS"),
        .description = COMPOUND_STRING("Si no lleva equipado ningún objeto, recupera la Poké Ball del primer intento de captura fallido."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("PELUSA"),
        .description = COMPOUND_STRING("Al ser alcanzado por un ataque, suelta una pelusa de algodón que reduce la Velocidad de todos los demás Pokémon."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("HÉLICE CAUDAL"),
        .description = COMPOUND_STRING("Impide que el rival pueda atraer ataques hacia sí mismo por efecto de su habilidad o sus movimientos."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("CORAZA REFLEJO"),
        .description = COMPOUND_STRING("Refleja los efectos que reducen las características."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("TRAGAMISIL"),
        .description = COMPOUND_STRING("Tras usar Surf o Buceo, emerge con una presa en la boca. Al recibir daño, ataca escupiéndola al rival."),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("ACÉRRIMO"),
        .description = COMPOUND_STRING("Impide que el rival pueda atraer ataques hacia sí mismo por efecto de su habilidad o sus movimientos."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("COMBUSTIBLE"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de tipo Fuego o Agua, le sube muchísimo la Velocidad."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("PUNK ROCK"),
        .description = COMPOUND_STRING("Potencia los movimientos que usan sonido y reduce a la mitad el daño que le infligen dichos movimientos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("EXPULSARENA"),
        .description = COMPOUND_STRING("Provoca una tormenta de arena al recibir un ataque."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("ESCAMA DE HIELO"),
        .description = COMPOUND_STRING("Las gélidas escamas que protegen su cuerpo reducen a la mitad el daño que le infligen los ataques especiales."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("MADURACIÓN"),
        .description = COMPOUND_STRING("Hace madurar las bayas, por lo que duplica sus efectos."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("CARA DE HIELO"),
        .description = COMPOUND_STRING("Absorbe el daño de un ataque físico con el hielo de la cabeza, tras lo cual cambia de forma. El hielo se regenerará la próxima vez que granice."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("FUENTE ENERGÍA"),
        .description = COMPOUND_STRING("Potencia los movimientos de los Pokémon adyacentes."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("MIMETISMO"),
        .description = COMPOUND_STRING("Cambia su tipo según el campo que haya en el terreno de combate."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("ANTIBARRERA"),
        .description = COMPOUND_STRING("Anula los efectos de Pantalla de Luz, Reflejo y Velo Aurora tanto de rivales como de aliados al entrar en combate."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("ALMA ACERADA"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Acero de los aliados."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("CUERPO MORTAL"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de contacto, se debilitará al cabo de 3 turnos, así como su agresor, a menos que abandonen el terreno de combate."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("ALMA ERRANTE"),
        .description = COMPOUND_STRING("Si le alcanza un movimiento de contacto, intercambia su habilidad con la del agresor."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("MONOTEMA"),
        .description = COMPOUND_STRING("Potencia su Ataque, pero solo puede usar el primer movimiento escogido."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("GAS REACTIVO"),
        .description = COMPOUND_STRING("Anula los efectos de las habilidades de los demás Pokémon presentes mientras esté en el terreno de combate."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("VELO PASTEL"),
        .description = COMPOUND_STRING("Se protege a sí mismo y a sus aliados del envenenamiento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("MUTAPETITO"),
        .description = COMPOUND_STRING("Alterna entre su Forma Saciada y Forma Voraz al final de cada turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("MANO RÁPIDA"),
        .description = COMPOUND_STRING("A veces, puede atacar el primero."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("PUÑO INVISIBLE"),
        .description = COMPOUND_STRING("Si usa un movimiento de contacto, puede infligir daño al objetivo aunque este se proteja."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("MEDICINA EXTRAÑA"),
        .description = COMPOUND_STRING("Al entrar en combate, rezuma una substancia medicinal por la caracola que revierte los cambios en las características de los aliados."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("TRANSISTOR"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Eléctrico."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("MANDÍBULA DRAGÓN"),
        .description = COMPOUND_STRING("Potencia los movimientos de tipo Dragón."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("RELINCHO BLANCO"),
        .description = COMPOUND_STRING("Al derrotar a un objetivo, emite un relincho gélido y aumenta su Ataque."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("RELINCHO NEGRO"),
        .description = COMPOUND_STRING("Al derrotar a un objetivo, emite un relincho aterrador y aumenta su Ataque Especial."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Unnerve and Chilling Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Unnerve and Grim Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("LINGERING AROMA"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("SEED SOWER"),
        .description = COMPOUND_STRING("Affects terrain when hit."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("THERMAL EXCHANGE"),
        .description = COMPOUND_STRING("Fire hits up Attack."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("ANGER SHELL"),
        .description = COMPOUND_STRING("Gets angry at half HP."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("PURIFYING SALT"),
        .description = COMPOUND_STRING("Protected by pure salts."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("WELL-BAKED BODY"),
        .description = COMPOUND_STRING("Strengthened by Fire."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("WIND RIDER"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("GUARD DOG"),
        .description = COMPOUND_STRING("Cannot be intimidated."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("ROCKY PAYLOAD"),
        .description = COMPOUND_STRING("Powers up Rock moves."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("WIND POWER"),
        .description = COMPOUND_STRING("Gets charged by wind."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("ZERO TO HERO"),
        .description = COMPOUND_STRING("Changes form on switch out."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("COMMANDER"),
        .description = COMPOUND_STRING("Commands from Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("ELECTROMORPHOSIS"),
        .description = COMPOUND_STRING("Gets Charged when hit."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("PROTOSYNTHESIS"),
        .description = COMPOUND_STRING("Sun boosts best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("QUARK DRIVE"),
        .description = COMPOUND_STRING("Elec. field ups best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("GOOD AS GOLD"),
        .description = COMPOUND_STRING("Avoids status moves."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("VESSEL OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' sp. damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("SWORD OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("TABLETS OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("BEADS OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' Sp. Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("ORICHALCUM PULSE"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("HADRON ENGINE"),
        .description = COMPOUND_STRING("Field becomes Electric."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("OPPORTUNIST"),
        .description = COMPOUND_STRING("Copies foe's stat change."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("CUD CHEW"),
        .description = COMPOUND_STRING("Eats a used berry again."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("SHARPNESS"),
        .description = COMPOUND_STRING("Strengthens slicing moves."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("SUPREME OVERLORD"),
        .description = COMPOUND_STRING("Inherits fallen's strength."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("COSTAR"),
        .description = COMPOUND_STRING("Copies ally's stat changes."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("TOXIC DEBRIS"),
        .description = COMPOUND_STRING("Throws poison spikes if hit."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("ARMOR TAIL"),
        .description = COMPOUND_STRING("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("EARTH EATER"),
        .description = COMPOUND_STRING("Eats ground to heal HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("MYCELIUM MIGHT"),
        .description = COMPOUND_STRING("Status moves never fail."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("HOSPITALITY"),
        .description = COMPOUND_STRING("Restores ally's HP."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("MIND'S EYE"),
        .description = COMPOUND_STRING("Keen Eye and Scrappy."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Speed."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Sp. Def."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Defense."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("TOXIC CHAIN"),
        .description = COMPOUND_STRING("Moves can poison."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("SUPERSWEET SYRUP"),
        .description = COMPOUND_STRING("Lowers the foe's Evasion."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("TERA SHIFT"),
        .description = COMPOUND_STRING("Terastallizes upon entry."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("TERA SHELL"),
        .description = COMPOUND_STRING("Resists all at full HP."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("TERAFORM ZERO"),
        .description = COMPOUND_STRING("Zeroes weather and terrain."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("POISON PUPPETEER"),
        .description = COMPOUND_STRING("Confuses poisoned foes."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
