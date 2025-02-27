# cs_memory_hack
Pulls data from a byte buffer at runtime, avoiding every single copy on load

- [x] C# 5.0 / Dot Net Standard 1.1 / .Net 4.5.1

When you want control over fast loading of data, you'll want to load your animation rotations as a huge byte buffer (ideally 1 for all anim rotations). Then, getting each quaternion value for animating at runtime is as simple as indexing a big array using pointer math. This avoids literally thousands of float object constructors and quaternion object constructors which are avoided, at a very small penalty (in C# a getter copies the value anyway when accessed). If you had an anim with 60 keyframes and 72 bones for the character, that is 17280 float copies and constructor calls avoided AND 4320 quaternion constructor calls avoided.

As for vertex and index buffers, it may be possible to deserialize them via `File.ReadAllBytes()` and `VertexBuffer.SetData<byte>()`.

For Elden Ring's enemies you would load in their 60 (FPS) * 60 (bones) * 10,000 (keyframes in all total animations) = 36 million quaternion initializations avoided while loading in all animation keyframe data.

The speed increase for this method is absolutely horrendous, because loading in your object graph is the second part after a single large bottleneck (slow part) disk I/O method, the `fread()` or `File.ReadAllBytes()`, and then on a modern gaming laptop you have 20 threads to multithread the object graph creation which has no disk reads (we initialize the classes from disk, then the instances pertain to the classes i.e. they are class instances with their own buffer memory offsets).
