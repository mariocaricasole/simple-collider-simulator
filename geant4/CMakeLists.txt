cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}/home/mario/Software/HepMC3/hepmc3-install/share/HepMC3/cmake)
find_package(HepMC3 3.2.6 REQUIRED)

include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

file(GLOB MACRO_FILES
	"*.mac"
)

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

file(GLOB DATA_FILES
	"*.dat"
)

file(COPY ${DATA_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(sim sim.cc ${sources} ${headers})
target_link_libraries(sim ${Geant4_LIBRARIES})
target_link_libraries(sim HepMC3::All)

add_custom_target(Simulation DEPENDS sim)
