${ALL}: ${DEPENDS}

${PROGRAM}: ${PROGRAM_OBJS}
	$(call PROGRAM_BUILD)

clean:
	@-rm -rf $(PROGRAM)
	@-rm -rf $(PROGRAM_OBJS)
	$(EXTRA_CLEAN)

test:
	$(call ECHO_VARS)
