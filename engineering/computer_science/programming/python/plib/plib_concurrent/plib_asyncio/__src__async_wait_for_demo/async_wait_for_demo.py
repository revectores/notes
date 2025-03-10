import asyncio
import time


async def go_sleep():
    await asyncio.sleep(3)
    print('wake!')

async def main():
    try:
        await asyncio.wait_for(go_sleep(), timeout=5)
        print('hello')
    except asyncio.TimeoutError:
        print('timeout!')

asyncio.run(main())
