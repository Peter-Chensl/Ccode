using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data;
using MySql.Data.MySqlClient;

namespace work
{
    public partial class Form1 : Form
    {
        private String SQL_ConnectStr = "server = localhost;port=3306;user=root;password=123456;database=book";
        public MySqlConnection MySqlConnection;

        MySqlDataAdapter mySqlDataAdpter;
        DataSet ds;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)//刷新按钮点击事件
        {
            ds.Tables["books"].Clear();
            mySqlDataAdpter.Fill(ds, "books");
        }
        private void button2_Click(object sender, EventArgs e)//保存按钮点击事件
        {
            MySqlCommandBuilder mycb = new MySqlCommandBuilder(mySqlDataAdpter);
            mySqlDataAdpter.Update(ds, "books");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Database_connection();
            Database_Select_All(MySqlConnection);
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
                string sql_select = "select * from books";
                MySqlCommand cmd = new MySqlCommand(sql_select, mySqlConnection);
                //将查询结果绑定dataview源
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "books");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "books";
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

        private void add_Click(object sender, EventArgs e)
        {
            Add form = new Add();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)//删除
        {

            string comm = "server = localhost;port=3306;user=root;password=123456;database=book";
            MySqlConnection sq = new MySqlConnection(comm);
            try
            {
                string sql = string.Format("select count from books where bookid='{0}'and count != 0 ", this.dataGridView1.CurrentCell.Value);//拼写sql语句删除用户
                sq.Open();
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                MySqlDataReader reader = cmd.ExecuteReader();
                
                if(reader.Read())
                {
                    int count = reader.GetInt32(reader.GetOrdinal("count"));
                    if (count > 0)
                    {
                        reader.Close();
                        string sql1 = string.Format("update books set count = count -1 where bookid = '{0}'", this.dataGridView1.CurrentCell.Value);
                        MySqlCommand cmd1 = new MySqlCommand(sql1, sq);

                        int y = cmd1.ExecuteNonQuery();
                        count--;
                        if (y != 0)
                        {
                            MessageBox.Show("更新成功！");
                            
                        }
                        else
                        {

                            MessageBox.Show("更新失败！");
                        }
                    }
                    if(count == 0)
                    {
                        sql = string.Format("delete from books where bookid = '{0}'", this.dataGridView1.CurrentCell.Value);
                        cmd = new MySqlCommand(sql, sq);
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

        private void button4_Click(object sender, EventArgs e)
        {
            搜索 form = new 搜索();
            form.Show();
        }

        private void button5_Click(object sender, EventArgs e)//退出
        {
            System.Environment.Exit(0);
        }
    }
}
