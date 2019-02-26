extra-tests := testpy

tests-y   := t1 t2
testscripts-y := test3.py

test3.py-driver := python3

testpy-y  := test.py
testpy-driver := python3

tests-y  += test2.py
test2.py-driver  := python3
test2.py-suffix  :=

t2-DEPS-y := a/liba.a
