#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/a08718a8/Bloque.o \
	${OBJECTDIR}/_ext/a08718a8/GameOverState.o \
	${OBJECTDIR}/_ext/a08718a8/MainMenuState.o \
	${OBJECTDIR}/_ext/a08718a8/Vector.o \
	${OBJECTDIR}/Juego.o \
	${OBJECTDIR}/LoadXML.o \
	${OBJECTDIR}/Mi_Sprite.o \
	${OBJECTDIR}/Mi_Texto.o \
	${OBJECTDIR}/Motor_2D.o \
	${OBJECTDIR}/Mundo.o \
	${OBJECTDIR}/Npc.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/Rads.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/inGame.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/mapa.o \
	${OBJECTDIR}/tinyxml2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-window.so /usr/lib/x86_64-linux-gnu/libsfml-audio.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: /usr/lib/x86_64-linux-gnu/libsfml-audio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/a08718a8/Bloque.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Bloque.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/Bloque.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Bloque.cpp

${OBJECTDIR}/_ext/a08718a8/GameOverState.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/GameOverState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/GameOverState.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/GameOverState.cpp

${OBJECTDIR}/_ext/a08718a8/MainMenuState.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/MainMenuState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/MainMenuState.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/MainMenuState.cpp

${OBJECTDIR}/_ext/a08718a8/Vector.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/Vector.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Vector.cpp

${OBJECTDIR}/Juego.o: Juego.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Juego.o Juego.cpp

${OBJECTDIR}/LoadXML.o: LoadXML.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LoadXML.o LoadXML.cpp

${OBJECTDIR}/Mi_Sprite.o: Mi_Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mi_Sprite.o Mi_Sprite.cpp

${OBJECTDIR}/Mi_Texto.o: Mi_Texto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mi_Texto.o Mi_Texto.cpp

${OBJECTDIR}/Motor_2D.o: Motor_2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor_2D.o Motor_2D.cpp

${OBJECTDIR}/Mundo.o: Mundo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mundo.o Mundo.cpp

${OBJECTDIR}/Npc.o: Npc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Npc.o Npc.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Rads.o: Rads.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rads.o Rads.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/inGame.o: inGame.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/inGame.o inGame.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/mapa.o: mapa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mapa.o mapa.cpp

${OBJECTDIR}/tinyxml2.o: tinyxml2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml2.o tinyxml2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
