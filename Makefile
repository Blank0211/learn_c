SHELL := pwsh.exe

# ==============
# [[ DEFAULTS ]]
# ==============
df1:
	clang waterfall.c -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

df2:
	gcc waterfall.c -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

# ===============
# [[ PROFILE_1 ]]
# ===============
s1: utils.o
	clang waterfall.c utils.o -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

utils.o: utils.c
	clang utils.c -c -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g

