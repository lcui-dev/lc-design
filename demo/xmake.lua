-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end

-- the release mode
if is_mode("release") then

    -- set the symbols visibility: hidden
    set_symbols("hidden")

    -- enable fastest optimization
    set_optimize("fastest")

    -- strip all symbols
    set_strip("all")
end

target("demo")
    set_kind("binary")
    set_targetdir("app/")
    add_files("src/*.c")
    add_files("src/ui/*.c")
    add_files("src/ui/views/*.c")
    add_files("src/ui/helpers/*.c")
    add_includedirs("include")
    add_includedirs("../include")
    add_includedirs("../../LCUI/include")
    add_includedirs("../vendor/include")
    add_linkdirs("../vendor/lib")
    add_linkdirs("../dist/lib")
    add_links("LCUI", "LCUIEx")