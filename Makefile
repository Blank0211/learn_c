SHELL := pwsh.exe

default:
	clang waterfall.c -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

gc:
	gcc waterfall.c -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

