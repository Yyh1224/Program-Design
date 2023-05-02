# Commands in subshell, that isolate Working Directory and Variables.
MVER = "version 5.0"
all:
	@                      echo -n "1)[$(MVER)] [$$VER] "  ; pwd
	@cd /usr/local ;       echo -n "2)[$(MVER)] [$$VER] "  ; pwd
	@VER="version A.2.3";  echo -n "3)[$(MVER)] [$$VER] "  ; pwd
	@MVER="version A.2.3"; echo -n "4)[$(MVER)] [$$MVER] " ; pwd
