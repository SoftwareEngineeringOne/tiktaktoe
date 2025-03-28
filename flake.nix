{
  description = "A basic flake with a shell";
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-24.11";
  inputs.systems.url = "github:nix-systems/default";
  inputs.flake-utils = {
    url = "github:numtide/flake-utils";
    inputs.systems.follows = "systems";
  };

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShell = pkgs.mkShell {
          packages = with pkgs; [
            entr
            doxygen
            graphviz
            perl
          ];
          nativeBuildInputs = with pkgs; [
            gcc-arm-embedded
            gdb
            clang-tools_19
            cmake
          ];

          buildInputs = with pkgs; [
          ];

        };
      }
    );
}
