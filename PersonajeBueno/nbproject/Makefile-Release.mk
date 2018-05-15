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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/a08718a8/Juego.o \
	${OBJECTDIR}/_ext/a08718a8/LoadXML.o \
	${OBJECTDIR}/_ext/a08718a8/Mundo.o \
	${OBJECTDIR}/_ext/a08718a8/inGame.o \
	${OBJECTDIR}/Mi_Sprite.o \
	${OBJECTDIR}/Mi_Texto.o \
	${OBJECTDIR}/Motor_2D.o \
	${OBJECTDIR}/Npc.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/Rads.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/mapa.o \
	${OBJECTDIR}/tinyxml2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personajebueno ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/a08718a8/Juego.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Juego.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/Juego.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Juego.cpp

${OBJECTDIR}/_ext/a08718a8/LoadXML.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/LoadXML.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/LoadXML.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/LoadXML.cpp

${OBJECTDIR}/_ext/a08718a8/Mundo.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Mundo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/Mundo.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/Mundo.cpp

${OBJECTDIR}/_ext/a08718a8/inGame.o: /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/inGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/a08718a8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a08718a8/inGame.o /home/natalia/Documentos/FV-Nuclear/fv-NuclearLeap/PersonajeBueno/inGame.cpp

${OBJECTDIR}/Mi_Sprite.o: Mi_Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mi_Sprite.o Mi_Sprite.cpp

${OBJECTDIR}/Mi_Texto.o: Mi_Texto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mi_Texto.o Mi_Texto.cpp

${OBJECTDIR}/Motor_2D.o: Motor_2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor_2D.o Motor_2D.cpp

${OBJECTDIR}/Npc.o: Npc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Npc.o Npc.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Rads.o: Rads.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rads.o Rads.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/mapa.o: mapa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mapa.o mapa.cpp

${OBJECTDIR}/tinyxml2.o: tinyxml2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml2.o tinyxml2.cpp

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
