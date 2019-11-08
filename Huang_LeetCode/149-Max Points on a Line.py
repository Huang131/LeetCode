from math import gcd
from collections import Counter


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) < 2:
            return len(points)
        points = [tuple(x) for x in points]
        P = Counter(points)

        def slop(p1, p2):  # 求出两点之间的斜率
            dx, dy = p2[0] - p1[0], p2[1] - p1[1]
            if dx == 0:
                return (0, 1)
            if dy == 0:
                return (1, 0)
            if dx < 0:
                dx = -dx
                dy = -dy
            g = gcd(dx, dy)  # 最大公约数
            return (dx // g, dy // g)

        lines = [Counter() for _ in range(len(points))]
        for i in range(1, len(points)):
            for j in range(i):
                if points[j] == points[i]:
                    continue
                k = slop(points[j], points[i])
                lines[i][k] += 1
                lines[j][k] += 1
        ans = 0
        for i, l in enumerate(lines):
            ans = max(ans, max(l.values(), default=0) + P[points[i]])
        return ans