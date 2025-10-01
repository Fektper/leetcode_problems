from typing import List

# def isInGrid(grid, pos):
#     return pos[0] >= 0 and pos[0] < len(grid[0]) and pos[1] >= 0 and pos[1] < len(grid)

# def findVSet0Turn(grid, pos, dx, dy, this_num, current_area):
#     # current position has already been added to area
#     next_num = 0 if this_num == 2 else 2
#     next_pos = pos[0] + dx, pos[1] + dy
#     while isInGrid(grid, next_pos) and grid[next_pos[1]][next_pos[0]] == next_num:
#         current_area += 1
#         next_num = 0 if next_num == 2 else 2
#         next_pos = next_pos[0] + dx, next_pos[1] + dy
    
#     return current_area

# def findVSet1Turn(grid, pos, dx, dy, this_num, current_area):
#     # pos is always this_num
#     straight_walk_area = current_area
#     next_num = 0 if this_num == 2 else 2

#     next_x, next_y = (pos[0] + dx, pos[1] + dy)
#     if isInGrid(grid, (next_x, next_y)):
#         if grid[next_y][next_x] == next_num:
#             straight_walk_area = findVSet1Turn(grid, (next_x, next_y), dx, dy, next_num, current_area + 1)
    
#     # turn area
#     turn_area = 0
#     turn_dx = -dx if dx*dy > 0 else dx
#     turn_dy = -dy if dx * dy < 0 else dy
#     turn_pos = pos[0] + turn_dx, pos[1] + turn_dy

#     if isInGrid(grid, turn_pos):
#         if grid[turn_pos[1]][turn_pos[0]] == next_num:
#             turn_area = findVSet0Turn(grid, turn_pos, turn_dx, turn_dy, next_num, current_area + 1)

    
#     return max(straight_walk_area, turn_area)
    


class TurnCache:
    def __init__(self, dim_x, dim_y):
        self.dim_x = dim_x
        self.dim_y = dim_y
        self.cache = [None] * dim_x * dim_y * 4

    def lookup(self, x, y, dx, dy):
        l_x = 0 if dx == -1 else 1
        l_y = 0 if dy == -1 else 2
        layer = l_x + l_y
        return self.cache[x + self.dim_x*y + (self.dim_x * self.dim_y * layer)]
    def insert(self, v, x, y, dx, dy):
        l_x = 0 if dx == -1 else 1
        l_y = 0 if dy == -1 else 2
        layer = l_x + l_y
        self.cache[x + self.dim_x*y + (self.dim_x * self.dim_y * layer)] = v

class Solution:
    def isInGrid(self, pos):
        return pos[0] >= 0 and pos[0] < self.x_dim and pos[1] >= 0 and pos[1] < self.y_dim

    def findVSet0Turn(self, pos, dx, dy, this_num, current_area):
        # current position has already been added to area
        next_num = 0 if this_num == 2 else 2
        next_pos = pos[0] + dx, pos[1] + dy
        while self.isInGrid(next_pos) and self.grid[next_pos[1]][next_pos[0]] == next_num:
            current_area += 1
            next_num = 0 if next_num == 2 else 2
            next_pos = next_pos[0] + dx, next_pos[1] + dy

        return current_area

    def findVSet1Turn(self, pos, dx, dy, this_num, current_area):
        # pos is always this_num
        additional_area = 0
        lookup = self.cache.lookup(pos[0], pos[1], dx, dy)
        if not lookup is None:
            additional_area = lookup
        else:
            next_num = 0 if this_num == 2 else 2

            next_x, next_y = (pos[0] + dx, pos[1] + dy)
            if self.isInGrid((next_x, next_y)):
                if self.grid[next_y][next_x] == next_num:
                    additional_area = self.findVSet1Turn((next_x, next_y), dx, dy, next_num, 1)

            self.cache.insert(additional_area, pos[0], pos[1], dx, dy)

        # turn area
        turn_area = 0
        turn_dx = -dx if dx*dy > 0 else dx
        turn_dy = -dy if dx * dy < 0 else dy
        turn_pos = pos[0] + turn_dx, pos[1] + turn_dy

        if self.isInGrid(turn_pos):
            if self.grid[turn_pos[1]][turn_pos[0]] == next_num:
                turn_area = self.findVSet0Turn(turn_pos, turn_dx, turn_dy, next_num, current_area + 1)


        return max(current_area + additional_area, turn_area)
    
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        self.x_dim = len(grid[0])
        self.y_dim = len(grid)
        self.grid = grid
        self.cache = TurnCache(self.x_dim, self.y_dim)

        start_positions = []
        for x in range(len(grid[0])):
            for y in range(len(grid)):
                if grid[y][x] == 1:
                    start_positions.append((x, y))
        max_area = 0
        for start_pos in start_positions:
            # print(f"\n{start_pos}", end = "") # 4, 2
            for dx in [-1, 1]:
                for dy in [-1, 1]:
                    area = self.findVSet1Turn(start_pos, dx, dy, 1, 1)
                    # print(f" : {area}", end="")
                    if area > max_area:
                        max_area = area

        return max_area
        


if __name__ == "__main__":
    test_input = [[2, 0, 2], [2, 0, 2]] # Get from .txt file, this is wrong!
    target_result = 5

    solver = Solution()
    res = solver.lenOfVDiagonal(test_input)
    if res == target_result:
        print("Test passed")
    else:
        print(f"Test failed! Expected {target_result} but got {res}")