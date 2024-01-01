import ctypes

def bug():
    ctypes.string_at(0)

bug()
