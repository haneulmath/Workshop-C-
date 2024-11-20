cmake_minimum_required(VERSION 3.20)

project(Workshop_Test)


# Trouve tous les fichiers .cpp dans mon répertoire src
file(GLOB CPP_FILES src/*.cpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS lib/random.cpp)

# Link the sil library into the project
add_subdirectory(lib/sil)

# Boucle sur chaque fichier cpp pour créer autant d'exe
foreach(CPP_NAME ${CPP_FILES}) # Pour chaque élément de cpp_files que j'appelle cpp_name
    # Nom du fichier sans le chemin ni l'extension
    get_filename_component(EXECUTABLE_NAME ${CPP_NAME} NAME_WE) # NAME_WE (Name Without Extension) précise que je veux uniquement le nom, sans l'extension
    message(${EXECUTABLE_NAME}) # Affiche le nom du fichier
    # Ajoute un exécutable avec le nom du fichier (sans extension)
    add_executable(${EXECUTABLE_NAME} ${CPP_NAME} ${SOURCES} )   # EXECUTABLE_NAME contient les noms des futurs fichiers executables et CPP_NAME contient le chemin des fichiers

# Choose your C++ version
    target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)

    # Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
        CXX_EXTENSIONS OFF)

    # Add all the source files
    target_include_directories(${EXECUTABLE_NAME} PRIVATE src lib)

    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE -DFILE_NAME="${EXECUTABLE_NAME}")

    target_link_libraries(${EXECUTABLE_NAME} PRIVATE sil)
    
endforeach()