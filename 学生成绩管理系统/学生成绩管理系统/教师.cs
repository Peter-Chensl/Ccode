using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace 学生成绩管理系统
{
    public partial class 教师 : Form
    {
        private String SQL_ConnectStr = "server = localhost;port=3306;user=root;password=123456;database=score";
        public MySqlConnection MySqlConnection;

        MySqlDataAdapter mySqlDataAdpter;
        DataSet ds;
        public 教师()
        {
            InitializeComponent();
        }
        public void Database_connection()
        {
            try
            {
                MySqlConnection = new MySqlConnection(SQL_ConnectStr);
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                Console.WriteLine("数据库连接成功");
            }
        }
        public void Database_Select_All(MySqlConnection mySqlConnection)
        {
            try
            {
                if (mySqlConnection != null)
                    mySqlConnection.Open();
                Console.WriteLine("查询");
                string sql_select = "select * from scores";
                MySqlCommand cmd = new MySqlCommand(sql_select, mySqlConnection);
                //将查询结果绑定dataview源
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "scores");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "scores";
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                mySqlConnection.Close();
            }
        }
        private void button3_Click(object sender, EventArgs e)
        {
            string comm = "server = localhost;port=3306;user=root;password=123456;database=score";
            MySqlConnection sq = new MySqlConnection(comm);
            try
            {
                string sql = string.Format("delete from scores where object = '{0}'", this.dataGridView1.CurrentCell.Value);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                sq.Open();
                int num = cmd.ExecuteNonQuery();
                if (num != -1)
                {
                    MessageBox.Show("删除成功！");
                }
                else
                {

                    MessageBox.Show("删除失败！");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                Application.Exit();
            }
            finally
            {
                sq.Close();
                sq.Dispose();

            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            添加 form = new 添加();
            form.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            成绩查询 form = new 成绩查询();
            form.Show();
        }

        private void 教师_Load(object sender, EventArgs e)
        {
            Database_connection();
            Database_Select_All(MySqlConnection);
        }
    }
}
