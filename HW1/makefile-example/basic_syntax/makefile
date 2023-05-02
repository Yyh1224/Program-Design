# Target1 Target2: Prerequisite1 Prerequisite2
#	Commands..
#	Commands..
1F:
	touch 1F
	echo -e "<<<hello world [1F]>>> - create 1F file\n"

2F: 1F
	@echo -e "<<<hello world [2F]>>> - don't create file\n"

3F: 1F 2F
	@echo -e "<<<hello world [3F]>>>"
	touch 2F 3F

clean:
	rm -f 1F 2F 3F
