-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end

-- the release mode
if is_mode("release") then

    -- enable fastest optimization
    set_optimize("fastest")

    -- strip all symbols
    set_strip("all")
end

target("LCUIEx")
    set_kind("shared")
    add_files("src/*.c")
    add_files("src/ui/*.c")
    add_files("src/ui/components/*.c")
    add_includedirs("include", "../LCUI/include", "vendor/include", "vendor/lib")
    add_links("LCUI")
    add_rpathdirs("/usr/local/lib")
    set_targetdir("dist/lib")
