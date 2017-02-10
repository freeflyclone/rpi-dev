${ALL}: ${DEPENDS}

${PROGRAM}: ${PROGRAM_OBJS}
	$(call PROGRAM_BUILD)

clean:
	@-rm -rf $(PROGRAM)
	@-rm -rf $(PROGRAM_OBJS)
	@-rm -rf $(PROGRAM).bin
	@-rm -rf $(PROGRAM).elf

test:
	$(call ECHO_VARS)
