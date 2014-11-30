#Clean up the mess#
- Move everything that should be in meta, to meta
- Put all the matchers files except one or two to matchers

#Allowing arbitrary user-defined sequence patterns#
- Create something like `make_pattern`, but for sequences
- Modeling after Scala's `unapplySeq`
- Consider everyone getting the same functionality as current `BSeq` magics
