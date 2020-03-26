#!/bin/bash
/home/hashish/egypt-1.10/egypt $@ | dot -Gsize=8,11  -Tpdf -o callgraph.pdf
