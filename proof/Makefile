# CUSTOMIZE
SYMAPI ?= $(HOME)/src/Verifier/LLVM/sym-api

MAKEFLAGS = --quiet

CPPFLAGS := -DINLEN=$(n) -DAIGFILE=encode.aig

prove: ../base64.cry encode.aig proof.cry
	cryptol -q -n proof.cry -b proof.scr | grep -E -v "Loading extern aig|^$$"

check: ../base64.cry encode.aig proof.cry
	cryptol -n proof.cry -c ":check MatchesRef"

%.bc: ../%.c
	clang -emit-llvm -I$(SYMAPI) -c $< -o $@

sym_encode.bc: sym_encode.c nvalue
	clang -emit-llvm -I.. -I$(SYMAPI) $(CPPFLAGS) -c $< -o $@

encode.bc: base64encode.bc sym_encode.bc
	llvm-link $^ -o $@

encode.aig: encode.bc
	lss $< > /dev/null

proof.cry: proof-template.cry nvalue
	cpp -P $(CPPFLAGS) $< > $@

nvalue:
ifndef n
	$(error Please specify a value for n. For example: make n=16)
endif

clean:
	rm -f *.bc *.aig proof.cry

.PHONY: prove check nvalue clean
