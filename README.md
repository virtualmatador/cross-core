# cross-core

# Setup project

1. Create "manifest.txt" at root. Example:
    target=<Project>
    identifier=<com.example.www>
    version=<Major.Minor>
    release=<Build Number>
    internet=<Internet Permission>
2. Create "icon.svg" at root.
3. Implement all functions inside src folder at root:
    namespace life_cycle
    {
        void Begin();
        void End();
        void Create();
        void Destroy();
        void Start();
        void Stop();
        void Restart();
    }
4. Derive calsses from core::Stage or core::Runner with source filse at src folder at root.
5. Instanciate core::Stage::stage_ by std::make_unique<> passing your classess as template argument.
