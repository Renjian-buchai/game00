DOXY_EXEC_PATH = U:/repos/game
DOXYFILE = U:/repos/game/Doxyfile
DOXYDOCS_PM = U:/repos/game/doc/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = U:/repos/game/doc/perlmod/DoxyStructure.pm
DOXYRULES = U:/repos/game/doc/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
