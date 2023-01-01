<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<CodeBlocks_project_file>
	<FileVersion major="1" minor="6" />
	<Project>
		<Option title="JoueurVSFauves" />
		<Option pch_mode="2" />
		<Option compiler="gcc" />
		<Build>
			<Target title="Debug">
				<Option output="bin/Debug/JoueurVSFauves" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Debug/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-g" />
				</Compiler>
			</Target>
			<Target title="Release">
				<Option output="bin/Release/JoueurVSFauves" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Release/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-O2" />
				</Compiler>
				<Linker>
					<Add option="-s" />
				</Linker>
			</Target>
		</Build>
		<Compiler>
			<Add option="-Wall" />
			<Add option="-fexceptions" />
		</Compiler>
		<Unit filename="arbres.cpp" />
		<Unit filename="arbres.h" />
		<Unit filename="conserver.h" />
		<Unit filename="elementMover.cpp" />
		<Unit filename="elementMover.h" />
		<Unit filename="elements.cpp" />
		<Unit filename="elements.h" />
		<Unit filename="elementsDeplacable.cpp" />
		<Unit filename="elementsDeplacable.h" />
		<Unit filename="fauves.cpp" />
		<Unit filename="fauves.h" />
		<Unit filename="interface.h" />
		<Unit filename="interfaceT.cpp" />
		<Unit filename="interfaceT.h" />
		<Unit filename="interfaceWinbgi.cpp" />
		<Unit filename="interfaceWinbgi.h" />
		<Unit filename="joueur.cpp" />
		<Unit filename="joueur.h" />
		<Unit filename="joueurExpert.cpp" />
		<Unit filename="joueurExpert.h" />
		<Unit filename="joueurNormal.cpp" />
		<Unit filename="joueurNormal.h" />
		<Unit filename="joueurNormalMover.cpp" />
		<Unit filename="joueurNormalMover.h" />
		<Unit filename="lion.cpp" />
		<Unit filename="lion.h" />
		<Unit filename="lionMover.cpp" />
		<Unit filename="lionMover.h" />
		<Unit filename="main.cpp" />
		<Unit filename="menu.cpp" />
		<Unit filename="menu.h" />
		<Unit filename="partie.cpp" />
		<Unit filename="partie.h" />
		<Unit filename="pieges.cpp" />
		<Unit filename="pieges.h" />
		<Unit filename="position.cpp" />
		<Unit filename="position.h" />
		<Unit filename="terrain.cpp" />
		<Unit filename="terrain.h" />
		<Unit filename="tigre.cpp" />
		<Unit filename="tigre.h" />
		<Unit filename="tigreMover.cpp" />
		<Unit filename="tigreMover.h" />
		<Extensions />
	</Project>
</CodeBlocks_project_file>
