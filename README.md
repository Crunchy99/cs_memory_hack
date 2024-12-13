# cs_memory_hack
Pulls animation data from a byte buffer at runtime, avoiding every single copy on load

When you want control over fast loading of data, you'll want to load your animation rotations as a huge byte buffer (ideally 1 for all anim rotations). Then, getting each quaternion value for animating at runtime is as simple as indexing a big array using pointer math. This avoids literally thousands of float object constructors and quaternion object constructors which are avoided, at a very small penalty (in C# a getter copies the value anyway when accessed).
