#Clean up the mess#
- Move everything that should be in meta, to meta
- Put all the matchers files except one or two to matchers

#Allowing arbitrary user-defined sequence patterns#
- Create something like `make_pattern`, but for sequences
- Modeling after Scala's `unapplySeq`
- Consider everyone getting the same functionality as current `BSeq` magics

#Other#
- Try to make tuple-based pattern compile errors more clear (now when matcher
  contains 2 expressions and the pattern 1, the error is huge and cryptic)

#Ideas for patterns#
- Regexp patterns ???
- `At` for maps
- Property-based patterns:

```
#!cpp
    NAMED_CASE(m, Record(_x = 23, _y = Pair('a', _1))) std::cerr << m->_1 << std::endl;
```

