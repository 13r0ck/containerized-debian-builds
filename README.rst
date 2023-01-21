Containerized Debian Build Experiment
=====================================

This works, but it doesn't. This logic could be copy pasted
into any debian package that uses static linking.
Unfortunatly LLVM doesn't do that. So this doesn't work for
Mesa...
I am keeping this arround mostly because debian packaging
(particularly when building in the sbuild environment)
imposes interesting limitations on podman and containers,
so this is one of the very few if not only way to make
this work. But also mostly because I put a lot of work into
it, and eventhough it isn't being used anywhere I am happy
that I got the packaging to work at all.
