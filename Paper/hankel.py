import math as m

def tX(bearing1, bearing2, r1X, r1Y, r2X, r2Y):
    tan1 = m.tan(bearing1)
    tan2 = m.tan(bearing2)
    return (r2Y - r1Y + r1X * tan1 - r2X * tan2)/(tan1 - tan2)

def tY(bearing1, bearing2, r1X, r1Y, r2X, r2Y):
    cot1 = m.cot(bearing1)
    cot2 = m.cot(bearing2)
    return (r2X - r1X + r1Y * cot1 - r2Y * cot2)/(cot1 - cot2)

def tempTx(tX, tY, rX, rY):
    return (tY - rY) / (tX - rX)

def tempTy(tX, tY, rX, rY):
    return (tX - rX) / (tY - rY)

def gX(tX, tY, t2X, t2Y, r1X, r1Y, r2X, r2Y):
    v1 = tempTx(tX, tY, r1X, r1Y)
    v2 = tempTx(t2X, t2Y, r1X, r1Y)
    return (v1 * r1X - v2 * r2X - r1Y + r2Y) / (v1 - v2)

def gY(tX, tY, t2X, t2Y, r1X, r1Y, r2X, r2Y):
    v1 = tempTy(tX, tY, r1X, r1Y)
    v2 = tempTy(t2X, t2Y, r1X, r1Y)
    return (r1Y * v1 - r2Y * v2 + r2X + r1X) / (v1 - v2)



