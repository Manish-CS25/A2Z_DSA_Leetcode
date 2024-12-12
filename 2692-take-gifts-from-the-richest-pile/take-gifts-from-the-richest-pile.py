
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = [-gift for gift in gifts]
        heapify(pq)
        while k:
            tmp = math.isqrt(-heappop(pq))
            heappush(pq , -tmp)
            k-=1
        return -sum(pq)
        