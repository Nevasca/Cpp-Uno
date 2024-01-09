# Cpp-Uno
 Uno game made in C++ using Windows console as user interface to practice the language.

## Uno Rules

This project will follow some of the [original rules](https://www.unorules.org/wp-content/uploads/2021/03/Uno-Rules-PDF-Official-Rules-unorules.org_.pdf) of the game, with some simplifications for now:

* Players only buy cards when none can be used, instead of the original rule of buying in any turn;
* First player chooses the first card to be placed on the table, instead of dealer placing the first from deck;
* No solo wildcard, just the +4 wildcard;
* No scoring.

The rules cut is to spare some time for the intended deadline. Missing rules will be added on the future.

## Setup

The solution was created using [Rider](https://www.jetbrains.com/pt-br/rider/) and [Visual Studio](https://visualstudio.microsoft.com/pt-br/vs/community/) toolset for compiling the project. If you don't have any of those IDE, a separate compiler will be required to run the project, such as CMake.

### Rider
* Make sure you have [Visual Studio](https://visualstudio.microsoft.com/pt-br/vs/community/) installed with C++ desktop development checked during installation (Rider uses this toolset for compiling);
* Open `Uno.sln` solution;
* On topmost right corner, use the play button to run the 'Uno' project.
