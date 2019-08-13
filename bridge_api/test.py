
import example as ex
# Make sure you copy the pyd file to this directory and rename it exmaple.pyd

A = [1.,2.,3.,4.]

B = ex.modify(A)

print(B)
print(ex.makeSquaresRange(100))
print(ex.helloString('Tina'))
d = ex.makeSquareMap(100)
print(type(d), 'RESULT->', d)
