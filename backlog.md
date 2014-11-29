#unapply for sequences#
##proposed syntax:##
```
Seq(_1,_2,_3,*_4) >> [1,2,3,4,5,6] yields 1,2,3,4,view(5,6)
Seq(_1,_2,_3,*_4) >> [1,2,3] yields 1,2,3,view()
Seq(_1,_2,_3,*_4) >> [1,2] breaks
Seq(_1,_2,_3) >> [1,2,3,4,5,6] breaks
Seq(_1,_2,_3) >> [1,2,3] yields 1, 2, 3
Seq(_1,_2,*_) >> [1,2,3,4,5,6] yields 1, 2
```
check that length is >=(number of non-starred placeholders).
the starred should always be the last (or the first ???) one
there should be only one starred placeholder (how to check?)
if there is no starred placeholders, the length should strictly equal the number of placeholders in touch

in question:
```
Seq(*_1, _2, _3) >> [1,2,3,4,5] yeilding view(1,2,3), 4, 5
Seq(_1, *_2, _3) >> [1,2,3,4,5] yeilding 1, view(2,3,4), 5
even more in question:
allow the star on arbitrary patterns, not only placeholders and ignore:
Seq(_1,_2,_3,_4,*(Seq(_5,_6,*_))) >> [1,2,3,4,5,6,7,8,9] yielding 1,2,3,4,5,6
```
    
#or-patterns#
##proposed syntax:##
```
(Pointer(_1) | _1) >> Pointer(Integer) yields Integer
(Pointer(_1) | _1) >> Integer yields Integer
(Pack(Unpack(_1)) | Unpack (Pack(_1)) | _1) >> Pack(Unpack(X)) yields X
                                            >> Unpack(Pack(X)) yields X
                                            >> X yields X
```


    problems: 
    - these will be allowed:
      (Pointer(_1) | _2) -- if we match the first pattern, we leave _2 uninit, if we match the second, we leave _1 uninit

      -- SEEMS WE CAN STATIC CHECK AND FORBID THESE, but it will leave this feature very limited 'cos there's no way to find out
         the actual pattern that produced the results

- and-patterns (the traditional hs uses @ symbol)
  possible syntax 1: &

     (_1 & Pointer(_2)) >> Integer breaks
                        >> Pointer(Integer) yields Pointer(Integer), Integer

  possible syntax 2: ^

     (_1 ^ Pointer(_2)) >> Integer breaks
                        >> Pointer(Integer) yields Pointer(Integer), Integer

  in question:
     allow arbitrary and-patterns:
         (Cons(Pointer(_1), _) & NonEmpty & Sorted)


