import re
import math


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        d = {}
        for i, n1 in enumerate(num1[::-1]):
            for j, n2 in enumerate(num2[::-1]):
                d[i + j] = d.get(i + j, 0) + (ord(n1) - 48) * (ord(n2) - 48)
        for k in [*d]:
            d[k +
              1], d[k] = d.get(k + 1, 0) + math.floor(d[k] * 0.1), d[k] % 10
        return re.sub('^0*', '', ''.join(map(str, d.values()))[::-1]) or '0'