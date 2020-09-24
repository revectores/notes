# Pygame

### 1. Framework

Here we demonstrate a basic framework of a pygame application.

```python
pygame.init()
clock = pygame.time.Clock()
FPS = 30

running = True

while running:
    clock.tick(FPS)

    for event in pygame.event.get():
		# multiple events handling
        
        if event.type == pygame.QUIT:
            running = False

    pygame.display.flip()
```

