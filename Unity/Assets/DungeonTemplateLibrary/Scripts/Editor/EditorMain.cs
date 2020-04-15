using UnityEditor;
using UnityEngine;

public enum DTL_CATEGORY {
    AscendingOrder = 0,
    Border,
    BorderOdd,
    CellularAutomatonIsland,
    DiamondSquareAverageCornerIsland,
    DiamondSquareAverageIsland,
    FractalIsland,
    PerlinIsland,
    PerlinSolitaryIsland,
    RandomRect,
    RogueLike,
    SimpleRogueLike
}

public class EditorMain : EditorWindow {
    public DTL_CATEGORY dtlOptions;
    private string topLabel = "DTL Template";
    private string hwLabel = "Size";
    private string templateLabel = "Code";
    private string dungeonScript = "";
    private int width;
    private int height;
    private Vector2 scroll;
    private float spacePixel = 10f;
    private Texture2D headerImage = null;

    private int depth;
    private int frequency;
    private int octaves;
    private int maxHeight;

//    [MenuItem("DTL/Editor Main")]
    public static void ShowWindow() {
        EditorWindow.GetWindow(typeof(EditorMain));
    }

    private void ShowHeaderImage() {
        if (headerImage == null) {
            headerImage = Resources.Load("Images/DTLHeaderFixed") as Texture2D;
        }
        else {
            float imageWidth = (float) headerImage.width;
            float imageHeight = (float) headerImage.height; 

            if (imageWidth > this.position.width + 10 ||
                imageHeight > this.position.height + 10) {
                var shrink = Mathf.Min(
                    this.position.width / imageWidth,
                    this.position.height / imageHeight);

                imageWidth *= shrink;
                imageHeight *= shrink;
                imageWidth -= 3.0f * shrink;
            }

            float posX = (this.position.width - imageWidth) / 2;
            float posY = 10.0f;

            EditorGUI.DrawPreviewTexture(new Rect(posX, posY, imageWidth, imageHeight), headerImage);
        }
    }

    string GenerateDTLTemplate(string op) {
        return $"/* DTL.Shape.{op} */\n\nvoid Start(){{\n    public int height = {height}\n    public int width = {width}\n\n";
    }

    string pushedButton(DTL_CATEGORY op) {
        string generateScript = GenerateDTLTemplate(op.ToString());
        switch (op) {
            case DTL_CATEGORY.PerlinIsland:
                generateScript += $"    public int depth = {depth}\n";
                generateScript += $"    public int frequency = {frequency}\n";
                generateScript += $"    public int octaves = {octaves}\n";
                generateScript += "    private Terrain terrain = GetComponent<Terrain>();\n\n";
                generateScript += "    private PerlinIsland perlinIsland = new PerlinIsland(frequency, octaves, maxHeight)\n";
                generateScript += "    public List<Texture2D> texture2D = new List<Texture2D>();\n\n";
                generateScript +=
                    "    TerrainUtil terrainUtil = \n    new TerrainUtil(terrain, texture2D, perlinIsland, height, width, depth);\n";
                generateScript += "    terrainUtil.Draw();\n}";
                break;
            default:
                // do nothing
                break;
        }

        return generateScript;
    }

    void OnGUI() {
//        ShowHeaderImage();

        GUILayout.Label(topLabel, EditorStyles.boldLabel);
        dtlOptions = (DTL_CATEGORY) EditorGUILayout.EnumPopup("Dungeon", dtlOptions);

        GUILayout.Label(hwLabel, EditorStyles.boldLabel);
        width = EditorGUILayout.IntField("width", width);
        height = EditorGUILayout.IntField("height", height);

        GUILayout.Space(spacePixel);

        switch (dtlOptions) {
            case DTL_CATEGORY.PerlinIsland:
                depth = EditorGUILayout.IntField("depth", depth);
                frequency = EditorGUILayout.IntField("frequency", frequency);
                octaves = EditorGUILayout.IntField("octaves", octaves);
                break;
        }

        // コードを生成、dungeonScriptにコードを挿入
        if (GUILayout.Button("Generate")) {
            dungeonScript = "";
            dungeonScript += pushedButton(dtlOptions);
        }

        GUILayout.Space(spacePixel);

        GUILayout.Label(templateLabel, EditorStyles.boldLabel);
        scroll = EditorGUILayout.BeginScrollView(scroll);
        dungeonScript = EditorGUILayout.TextArea(dungeonScript, GUILayout.Height(position.height / 2));
        EditorGUILayout.EndScrollView();
    }
}